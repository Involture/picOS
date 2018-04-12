#include <stdio.h>
#include <kernel/dump.h>

#include <kernel/interrupt.h>

void interrupt_master_isr(struct dump_as_reg_dump rdump, uint32_t interrupt,
                          struct dump_as_interrupt_dump idump) {
  uint32_t inter = interrupt;
  puts("Hello, Im the master interrupt handler");
  printf("I was called with interrupt number : %x\n", inter, 4);
  puts("Here are the dumps !");
  dump_print_reg(&rdump);
  dump_print_interrupt(&idump);
}
