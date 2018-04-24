#ifndef _KERNEL_DTCONF_H
#define _KERNEL_DTCONF_H

#include <kernel/dt.h>

// Structures used to store the descriptor tarbles. These are not the
// tables that are loaded in the cpu as the bits of the entries need to be
// reordered first.
extern struct gdt_entry gdt_conf[];
extern struct idt_entry idt_conf[];

#endif
