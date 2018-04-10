.att_syntax noprefix

.section .data
dtr: 
  .word 0x0 # For limit storage
  .long 0x0 # For base storage

.section .text
.global dt_set_gdt
.global dt_set_idt
.global dt_reload_cs
.type dt_set_gdt, @function
.type dt_set_idt, @function
.type dt_reload_cs, @function

# void dt_set_gdt(uint64_t* gdt, size_t size)
dt_set_gdt :
  mov 4(esp), eax
  mov eax, 2 + dtr
  mov 8(esp), ax
  mov ax, dtr
  lgdt dtr
  ret

# void dt_set_idt(uint64_t* idt, size_t size)
dt_set_idt :
  mov 4(esp), eax
  mov eax, 2 + dtr
  mov 8(esp), ax
  mov ax, dtr
  lidt dtr
  ret

# void dt_reload_cs(void)
dt_reload_cs :
  xor eax, eax
  mov $0x08, ax
  mov eax, es
  jmp es:.reload_cs
.reload_cs :
  xor eax, eax
  mov $0x10, ax
  mov ax, es
  mov ax, ds
  mov ax, es
  mov ax, fs
  mov ax, gs
  mov ax, ss
  ret
