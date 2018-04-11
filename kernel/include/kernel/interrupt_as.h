#ifndef _KERNEL_INTERRUPT_AS_H
#define _KERNEL_INTERRUPT_AS_H

#include <stdint.h>

#define INTERRUPT_AS_ENTRY_POINT_OFS 14

extern void interrupt_as_isr_wrapper(void);
extern void interrupt_as_raise(void);

extern uint32_t debug1;
extern uint32_t debug2;
extern uint32_t debug3;

#endif
