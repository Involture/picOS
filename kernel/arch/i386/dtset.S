.intel_syntax noprefix

.section .data
gdtr: 
  .word 0 # For limit storage
  .long 0 # For base storage

.section .text
.global set_gdt
.global reload_cs
.type set_gdt, @function
.type reload_gdt, @function

# void set_gdt(uint64_t* gdt, size_t size)
set_gdt :
  mov eax, [esp + 4]
  mov [gdtr + 2], eax
  mov ax, [esp + 8]
  mov [gdtr], ax
  lgdt [gdtr]
  ret

reload_cs :
  jmp 0x08:.reload_cs
.reload_cs :
  mov ax, 0x10
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  mov ss, ax
  ret
