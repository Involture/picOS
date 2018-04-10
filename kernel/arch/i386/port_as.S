.att_syntax noprefix

.section .text
.global outb
.global inb
.type outb, @function
.type inb, @function

# void outb(int port, char entry)
outb:
  xor eax, eax
  mov 4(esp), al
  mov 8(esp), dl
  out ax, dx
  ret

#char inb(int port)
inb:
  xor eax, eax
  mov 4(esp), dl
  in dx, ax
  ret
