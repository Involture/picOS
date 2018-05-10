#ifndef _KERNEL_DTSET_H
#define _KERNEL_DTSET_H

// Reorder bits of the tables to produce the final ones, and load them in the
// processor.
void dt_init_gdt(void);
void dt_init_idt(void);

// Print the tables as they are loaded in the processor.
void dt_print_gdt(void);
void dt_print_idt(void);

#endif
