#ifndef _KERNEL_TIME_H
#define _KERNEL_TIME_H

void timer_isr(void);
unsigned long long ms_counter;
unsigned long long s_counter;

#endif
