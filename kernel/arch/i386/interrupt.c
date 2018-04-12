#include <stdio.h>
#include <kernel/dump.h>
#include <kernel/dump_as.h>

#include <kernel/interrupt.h>

void interrupt_master_isr(struct dump_as_reg_dump rdump, uint32_t interrupt,
                          struct dump_as_interrupt_dump idump) {
  uint32_t stack_dump[12];
  puts("Hello, Im the master interrupt handler");
  dump_as_stack(stack_dump, 12);
  dump_print_stack(stack_dump, 12);
  while(1);
  printf("I was called with interrupt number : %x\n", interrupt, 4);
  puts("Here are the dumps !");
  dump_print_reg(&rdump);
  dump_print_interrupt(&idump);
}
