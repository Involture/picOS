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

# Reserve a stack for the initial thread.
.section .bss

# Global variables
.global stack_bottom
.global stack_top
.global debug_stack_bottom
.global debug_stack_top

.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# Reserve a stack for a second kernel thread, for debuging purpose for the
# moment.
.align 16
debug_stack_bottom:
.skip 16384
debug_stack_top:

# The kernel entry point.
.section .text
.global _start
.type _start, @function

_start:
	movl $stack_top, esp

	# Call the global constructors.
	call _init

	# Transfer control to the main kernel.
  push ebx
	call kernel_main

	# Hang if kernel_main unexpectedly returns.
	cli
  hlt
.size _start, . - _start
