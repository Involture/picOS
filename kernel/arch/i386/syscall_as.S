.att_syntax noprefix

.section .text
.global syscall
.global syscall_enable
.global syscall_set_stack

.type syscall, @function
.type syscall_enable, @function
.type syscall_set_stack, @function

# void syscall(size_t, void*, size_t)
syscall :
  # Saving ebx
  push ebx

  # Moving stack argument to registers
  mov 8(ebp), eax
  mov 12(ebp), ebx
  mov 16(ebp), edx
  
  # Saving stack address
  mov esp, ecx

  # Entering kernel
  sysenter

syscall_return_point:  
  pop ebx 
  ret

syscall_entry_point_wrapper :
  # Pushing user stack pointer
  push ecx

  # Moving register arguments to stack
  push edx
  push ebx
  push eax
  
  # Calling C code
  call syscall_master_handler

  # Returning
  add 12, esp
  pop ecx
  mov $syscall_return_point, edx
  sysret

# void syscall_enable(void)
syscall_enable :
  # Setting the kernel code segment
  mov $0x174, ecx
  rdmsr
  mov $0x0000, ax
  wrmsr

  # Setting the kernel entry point.
  mov $0x176, ecx
  rdmsr
  mov $syscall_entry_point_wrapper, eax
  wrmsr

  ret

syscall_set_stack :
  # Writing the msr
  mov $0x175, ecx
  rdmsr
  mov 4(esp), eax   # Retreive the argument
  wrmsr
  ret

