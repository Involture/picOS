#ifndef _KERNEL_INTERRUPT_H
#define _KERNEL_INTERRUPT_H

#include <stdint.h>

#define EXCEPTION_DIVIDE_ZERO         0x0
#define EXCEPTION_DEBUG               0x1
#define EXCEPTION_NMI                 0x2
#define EXCEPTION_BREAK               0x3
#define EXCEPTION_OVERFLOW            0x4
#define EXCEPTION_RANGE_EXCEDEED      0x5
#define EXCEPTION_INVALID_OP          0x6
#define EXCEPTION_DEV_NOT_AVAILABLE   0x7
#define EXCEPTION_DOUBLE              0x8
#define EXCEPTION_INVALID_TSS         0xA
#define EXCEPTION_SEG_NOT_PRESENT     0xB
#define EXCEPTION_STACK_SEG_FAULT     0xC
#define EXCEPTION_GPF                 0xD
#define EXCEPTION_PAGE_FAULT          0xE
#define EXCEPTION_87FP                0x10
#define EXCEPTION_ALIGNEMENT_CHECK    0x11
#define EXCEPTION_MACHINE_CHECK       0x12
#define EXCEPTION_SMIDFP              0x13
#define EXCEPTION_VIRTUALIZATION      0x14

// EXTERN ASSEMBLY FUNCTIONS

extern void interrupt_enable(void);
extern void interrupt_disable(void);
extern void interrupt_test(void);

//

#endif
