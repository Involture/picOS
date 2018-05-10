.att_syntax noprefix

.section .text
.global dt_set_gdt
.global dt_set_idt
.global dt_reload_cs
.type dt_set_gdt, @function
.type dt_set_idt, @function
.type dt_reload_cs, @function

# void dt_set_gdt(struct dt_ptr*)
dt_set_gdt :
  lgdt 4(esp)
  ret

# void dt_set_idt(struct dt_ptr*)
dt_set_idt :
  lidt 4(esp)
  ret

# void dt_reload_cs(void)
dt_reload_cs :
  ljmp $0x08, $.reload_cs
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
