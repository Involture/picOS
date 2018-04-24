#ifndef _KERNEL_INTERRUPT_H
#define _KERNEL_INTERRUPT_H

#include <stdint.h>
#include <kernel/dump_as.h>

/* The master interrupt handler (isr = interrupt service routine).
   The isr_wrappers, writtent in assembly, calls it with the relevant interrupt
   number. (See kernel/interrupt_as.h)
 */
void interrupt_master_isr(struct dump_as_reg_dump, uint32_t interrupt,
                          struct dump_as_interrupt_dump);

#endif
