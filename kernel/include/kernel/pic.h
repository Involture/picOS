#ifndef _KERNEL_PIC_H
#define _KERNEL_PIC_H

#include <stdint.h>

void pic_sendEOI(unsigned char);
void pic_remap(uint32_t, uint32_t, uint16_t);
extern void pic_disable_apic(void);

#endif
