.att_syntax noprefix

.section .text
.global disable_apic
.type disable_apic, @function
disable_apic:
  mov 0x0000001B, ecx
  mov 0x0, eax
  mov 0x0, edx
  wrmsr
  ret
