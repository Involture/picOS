#include <stdio.h>
#include <kernel/dump.h>

#include <kernel/interrupt.h>

void interrupt_master_isr(struct dump_as_reg_dump rdump, uint32_t interrupt,
                          struct dump_as_interrupt_dump idump) {
  struct dump_as_reg_dump rd = rdump;
  struct dump_as_interrupt_dump id = idump;
  puts("Hello, Im the master interrupt handler");
  printf("I was called with interrupt number : %w\n", &interrupt, 4);
  puts("Here are the dumps !");
  dump_print_reg(&rd);
  dump_print_interrupt(&id);
}
