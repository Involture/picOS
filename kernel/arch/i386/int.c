#include <kernel/dt.h>
#include <stdio.h>

#include <kernel/int.h>

void isr0(int n) {
  puts("OMFG, interruptions are working :o");
  printf("Btw, I was called by interrupt n_%x\n", n);
};

void (*isr_vector[IDT_SIZE])(int) = { &isr0 };
