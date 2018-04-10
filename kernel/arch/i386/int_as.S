.att_syntax noprefix

.section .text
.global isr_wrapper
.global isr_vector
.type isr_wrapper, @function

#void isr_wrapper(int)
isr_wrapper :
  mov 4(esp), eax
  push 4(esp)
  pushal
  cld
  call isr_vector(eax)
  popal
  add $4, esp
  iret
