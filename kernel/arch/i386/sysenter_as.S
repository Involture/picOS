/* Sysenter conventions :

   When calling sysenter, the following conditions must be met :
   - eax must contain the call code.
   - ebx is reserved for now.
   - ecx must contain the stack pointer just before calling sysenter.
   - edx must contain the return instruction pointer.
   - edi must contain the data pointer for the system call.
   - esi must contain the size of this data.
   No register except esp is saved across system call.
   
   After sysexit you can expect :
   - eax to contain a pointer to the data returned by the kernel.
   - ebx to contain the data size.
   NO OTHER REGISTER TO HAVE DEFINED VALUE.
 */

.att_syntax noprefix
.global sysenter_init
.global sysexit
.global sysreturn

.type sysenter_init, @function
.type sysexit, @function
.type sysreturn, @function

.section .data.
sysenter_return_eip :    .long 0x00000000
sysenter_return_esp :    .long 0x00000000
sysenter_return_data :   .long 0x00000000
sysenter_return_size :   .long 0x00000000
sysenter_returned_flag : .byte 0x00

.section .text

syscall_entry_point_wrapper :
  # Pushing arguments
  push esi
  push edi
  push edx
  push ecx
  push eax

  # Setting the returned flag to false
  movb $1, sysenter_returned_flag

  # Calling C code
  call sysenter_master_handler
  # This handler should never return !!!
  cli
  hlt

# void sysenter_init(void)
sysenter_init :
  # Setting the kernel code segment
  mov $0x174, ecx
  rdmsr
  mov $0x0008, ax
  wrmsr

  # Setting the kernel entry point.
  mov $0x176, ecx
  rdmsr
  mov $syscall_entry_point_wrapper, eax
  wrmsr

  # Setting the kernel stack.
  mov $0x175, ecx
  rdmsr
  mov $debug_stack_top, eax
  wrmsr

  ret

# void sysreturn(uint32_t, uint32_t, task_data_t*)
sysreturn:
  mov sysenter_returned_flag, al
  test al, al
  jz already_returned

  movb $0, sysenter_returned_flag

  mov 4(esp), eax
  mov eax, sysenter_return_eip

  mov 8(esp), eax
  mov eax, sysenter_return_esp

  mov 12(esp), eax
  mov (eax), ecx
  mov ecx, sysenter_return_data

  mov 4(eax), ecx
  mov ecx, sysenter_return_data

  mov $0, eax
  ret

already_returned:
  mov $1, eax
  ret


# bool sysexit()
# Dont forget ! On sysexit, the kernel stack is discarded !!!
sysexit :

  mov sysenter_return_data, eax
  mov sysenter_return_size, ebx
  mov sysenter_return_esp, ecx
  mov sysenter_return_eip, edx

  sysexit
