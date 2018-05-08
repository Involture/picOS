.att_syntax noprefix

.section .text
.global syscall
.type syscall, @function

# void* syscall(size_t, void*, size_t)
syscall :
    
  # Saving registers not saved by syscall :
  push ebp
  mov esp, ebp
  push ebx
  push edi
  push esi

  # Setting syscall argument
  mov 8(ebp), eax
  mov esp, ecx
  mov $syscall_return_point, edx
  mov 12(ebp), edi
  mov 16(ebp), esi
  
  # Entering kernel
  sysenter

syscall_return_point:
  pop esi
  pop edi
  pop edx
  pop ebp
  ret

