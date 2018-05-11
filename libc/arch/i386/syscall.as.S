.att_syntax noprefix

.global syscall

.type syscall, @function

.section .text

# struct data_t* syscall(uin16_t, struct data_t*)
syscall :
  # Saving registers
  push ebp
  mov esp, ebp
  push ebx
  push edi
  push esi
  
  # Putting argument in registers
  mov 8(ebp), eax
  mov 12(ebp), edi
  mov esp, ecx
  mov $return_point, edx
  sysenter

return_point:
  pop esi
  pop edi
  pop ebx
  pop ebp
  ret
