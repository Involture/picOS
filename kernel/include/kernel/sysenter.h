#ifndef _KERNEL_SYSENTER_H
#define _KERNEL_SYSENTER_H

#include <stdint.h>
#include <schtyp.h>
#include <task.h>

extern void sysenter_init(void);
extern void sysexit(void)
__attribute__((__noreturn__));
extern bool sysreturn(uint32_t, uint32_t, struct data_t*);

#endif
