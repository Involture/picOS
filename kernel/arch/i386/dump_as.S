.att_syntax noprefix

.section .data
to_print :
  .double 0
format :
  .ascii "eax : %w  \n"

.section .text
.global dump_as_reg
.global dump_as_seg
.global dump_as_stack
.type dump_as_reg, @function
.type dump_as_seg, @function
.type dump_as_stack, @function

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

# void dump_as_stack(uint32_t* ptr, size_t size)
dump_as_stack :
  push edi
  mov 12(esp), eax
  mov 8(esp), ecx
  mov $16, edx
while_begin :

# Print for debugging
  push $4
  push $to_print
  push $format
  mov eax, to_print
  call printf
  mov ecx, to_print
  call printf
  mov edx, to_print
  call printf
  add $12, esp

  mov (esp, edx), edi
  mov edi, (ecx)
  add $4, ecx
  add $4, edx
  sub $1, eax
  jz while_end
  jmp while_begin
while_end :
  pop edi
  ret
