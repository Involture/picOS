.att_syntax noprefix

.section .text
.global outb
.global inb
.type outb, @function
.type inb, @function

# void outb(int port, char entry)
outb:
  xor eax, eax
  xor edx, edx
  mov 4(esp), dl
  mov 8(esp), al
  out al, dx
  ret

#char inb(int port)
inb:
  xor eax, eax
  mov 4(esp), dl
  in dx, al
  ret
