.att_syntax noprefix

.section .text
.global dump_as_reg
.global dump_as_seg
.type dump_as_reg, @function
.type dump_as_seg, @function

# void dump_as_reg(struct dump_as_reg_dump*)
  push edx
  push eax
  mov 12(esp), eax
  mov ebx, 4(eax)
  mov ecx, 8(eax)
  mov edx, 12(eax)
  mov esp, 16(eax)
  mov ebp, 20(eax)
  mov esi, 24(eax)
  mov edi, 28(eax)
  mov eax, edx
  pop eax
  mov eax, (edx)
  pop edx
  ret

# void dump_as_seg(struct dump_as_seg_dump*)
dump_as_seg :
  mov 4(esp), eax
  mov cs, (eax)
  mov ds, 4(eax)
  mov es, 8(eax)
  mov fs, 12(eax)
  mov gs, 16(eax)
  mov ss, 20(eax)
  ret
