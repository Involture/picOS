.att_syntax noprefix

.section .text
.global pic_disable_apic
.type pic_disable_apic, @function
pic_disable_apic:
  mov 0x0000001B, ecx
  mov 0x0, eax
  mov 0x0, edx
  wrmsr
  ret
