#ifndef _KERNEL_DUMP_H
#define _KERNEL_DUMP_H
#include <stdint.h>

#include <kernel/dump_as.h>

void dump_print_reg (struct dump_as_reg_dump*);
void dump_print_seg (struct dump_as_seg_dump*);
void dump_print_interrupt (struct dump_as_interrupt_dump*);
void dump_print_stack (uint32_t*, size_t);

#endif
