.att_syntax noprefix

# Declare constants for the multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .pages , "wa", @nobits
.skip 0x00404000

.section .lower , "ax"

.global lower_start
.type lower_start, @function

lower_start:
  # Setting page tables
  call paging_init

  # Enabling paging
  mov $PHYSICAL_DIRECTORY_TABLE, ecx
  mov ecx, cr3
  mov cr4, ecx
  and $0xFFFFFFEF, ecx       # Disable big pages
  mov ecx, cr4
  mov cr0, ecx
  or $0x80000000, ecx        # Enable paging
  mov ecx, cr0
  mov $upper_start, ecx
  jmp *ecx

paging_init :

  # Setting the directory table

  xor ecx, ecx
  mov $LOADER_DIR_NUMBER, eax
  add $LOWER_DIR_NUMBER, eax
loop_load_lower_dir :
  mov ecx, edx
  call mk_dir_desc
  inc ecx
  cmp ecx, eax
  je end_load_lower_dir
  jmp loop_load_lower_dir
end_load_lower_dir :

  mov $UPPER_VIRTUAL_DIR, eax
  sub $1, eax
loop_empty_dir :
  mov ecx, edx
  call mk_empty_dir
  inc ecx
  cmp ecx, eax
  je end_empty_dir
  jmp loop_empty_dir
end_empty_dir :

  mov $LOADER_DIR_NUMBER, edx
  add $LOWER_DIR_NUMBER, edx
  call mk_dir_desc
  inc ecx

  mov $TOTAL_DIR_NUMBER, eax
loop_upper_dir :
  mov ecx, edx
  call mk_dir_desc
  inc ecx
  cmp ecx, eax
  je end_upper_dir 
  jmp loop_upper_dir
end_upper_dir :

  # Setting the page table

  xor ecx, ecx
  mov $LOADER_PAGE_NUMBER, eax
  add $LOWER_PAGE_NUMBER, eax
loop_load_lower_page :
  mov ecx, edx
  call mk_page_desc
  inc ecx
  cmp ecx, eax
  je end_load_lower_page
  jmp loop_load_lower_page
end_load_lower_page :

  mov $UPPER_VIRTUAL_PAGE, eax
  sub $1, eax
loop_empty_page :
  mov ecx, edx
  call mk_empty_page
  inc ecx
  cmp ecx, eax
  je end_empty_page
  jmp loop_empty_page
end_empty_page :

  mov $LOADER_PAGE_NUMBER, edx
  add $LOWER_PAGE_NUMBER, edx
  call mk_page_desc
  inc ecx

  mov $TOTAL_PAGE_NUMBER, eax
  mov ecx, edx
  sub $UPPER_PAGE_OFFSET, edx
loop_upper_page :
  call mk_page_desc
  inc edx
  inc ecx
  cmp ecx, eax
  je end_upper_page
  jmp loop_upper_page
end_upper_page :

ret

mk_empty_dir :
  .set permission, 0x00
  jmp dir_perm_def_end
mk_dir_desc :
  .set permission, 0x83
dir_perm_def_end :
  mov ecx, edi
  shl $2, edi
  mov edx, esi
  shl $12, esi
  add $permission, esi
  add $PHYSICAL_PAGE_TABLE, esi
  mov esi, PHYSICAL_DIRECTORY_TABLE(edi)
  ret

mk_empty_page :
  .set permission, 0x00
  jmp page_perm_def_end
mk_page_desc :
  .set permission, 0x83
page_perm_def_end :
  mov ecx, edi
  shl $2, edi
  mov edx, esi
  shl $12, esi
  add $permission, esi
  mov esi, PHYSICAL_PAGE_TABLE(edi)
  ret

.section .text

upper_start:
  # Enabling stack !
  mov $KERNEL_STACK_TOP, esp

	# Call the global constructors.
	call _init

	# Transfer control to the main kernel.
  push ebx
	call kernel_main

	# Hang if kernel_main unexpectedly returns.
	cli
  hlt
