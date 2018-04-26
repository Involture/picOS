.att_syntax no_prefix

.text
.global syscall

.type syscall, @function

syscall :

  # Initialising new stack frame
  mov esp, ebp
  push esp

  # Pushing the data on the user stack
  mov $4(ebp), ecx
  xor edx, edx
  test ecx, ecx
for_loop :
  jz for_end
  mov (ebp, edx) eax
  push eax
  incr edx
  decr ecx
  jmp for_loop
for_end :
