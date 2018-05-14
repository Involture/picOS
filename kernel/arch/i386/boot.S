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

.section .data
# This tables :
# identity maps
#   - The first kernel page
#   - The first Mib
# Maps the 2 Mib kernel from 1Mib to 3Gib+1022Mib

.set LOADER_SIZE,          0x00100000
.set LOADER_PAGE_NUMBER,   (LOADER_SIZE >> 12)
.set LOADER_DIR_NUMBER,    (LOADER_PAGE_NUMBER >> 10)

.set KERNEL_VIRTUAL_BASE,  0xFEFFFFFF
.set KERNEL_VIRTUAL_PAGE,  (KERNEL_VIRTUAL_BASE >> 12)
.set KERNEL_VIRTUAL_DIR,   (KERNEL_VIRTUAL_PAGE >> 10)

.set KERNEL_PHYSICAL_BASE, 0x00100000
.set KERNEL_PHYSICAL_PAGE, (KERNEL_PHYSICAL_BASE >> 12)
.set KERNEL_PHYSICAL_DIR,  (KERNEL_PHYSICAL_PAGE >> 10)

.set KERNEL_SIZE,          0x01000000
.set KERNEL_PAGE_NUMBER,   (KERNEL_SIZE        >> 12)
.set KERNEL_DIR_NUMBER,    (KERNEL_PAGE_NUMBER >> 10)

.set TOTAL_PAGE_NUMBER,    0x00100000
.set TOTAL_DIR_NUMBER,     (TOTAL_PAGE_NUMBER >> 10)

.macro define_page n
  .long ((\n << 12) + 0x83)
.endm
.macro define_empty_page
  .long 0
.endm
.macro define_accessible_directory n
  .long ((\n << 12) + page_tables + 0x83)
.endm
.macro define_empty_directory
  .long 0
.endm

.align 0x00001000

# Generated file see paging_tables.generator
#include "paging_tables.data"

# Defining a stack
.global _kernel_stack
.set _kernel_stack, (KERNEL_VIRTUAL_BASE - 1)

# The kernel entry point.
.section .text

.global _start
.type _start, @function

.set _start, (start - KERNEL_VIRTUAL_BASE + KERNEL_PHYSICAL_BASE)

start:
  # Setting paging
  mov (directory_table - KERNEL_VIRTUAL_BASE), ecx
  mov ecx, cr3
  mov cr4, ecx
  and 0x00000010, ecx       # Disable big pages
  mov ecx, cr4
  mov cr0, ecx
  or ecx, 0x80000000        # Enable pages
  mov ecx, cr0
  mov $start_upper, ecx
  jmp *ecx

start_upper:
  # Unmap the first page.
  movl $0x0, (page_tables + KERNEL_PHYSICAL_PAGE)

	# Call the global constructors.
	call _init

	# Transfer control to the main kernel.
  push ebx
	call kernel_main

	# Hang if kernel_main unexpectedly returns.
	cli
  hlt
