.att_syntax noprefix

.section .data
dtr: 
  .word 0x0 # For limit storage
  .long 0x0 # For base storage

seg_drop:
  .long 0x0 # For cs drop
  .long 0x0 # For ds drop
  .long 0x0 # For es drop
  .long 0x0 # For fs drop
  .long 0x0 # For gs drop
  .long 0x0 # For ss drop

.section .text
.global dt_set_gdt
.global dt_set_idt
.global dt_reload_cs
.global dt_drop_seg
.global dt_raise
.type dt_set_gdt, @function
.type dt_set_idt, @function
.type dt_reload_cs, @function
.type dt_drop_seg, @function
.type dt_raise, @function

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

# uint32_t* dt_drop_seg(void)
dt_drop_seg :
  mov cs, seg_drop
  mov ds, seg_drop + 4
  mov es, seg_drop + 8
  mov fs, seg_drop + 12
  mov gs, seg_drop + 16
  mov ss, seg_drop + 20
  lea seg_drop, eax
  ret

# void dt_raise(void)
dt_raise :
  int $0x00
  ret
