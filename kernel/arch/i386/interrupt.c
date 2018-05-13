#include <stdio.h>
#include <stdbool.h>

#include <kernel/dump.h>
#include <kernel/ps2_ctrl.h>
#include <kernel/pic.h>
#include <kernel/interrupt.h>
#include <kernel/time.h>

#include <kernel/ps2_kbd_kmp.h>

// GLOBAL FUNCTIONS

void interrupt_master_isr(struct dump_as_reg_dump rdump, uint32_t interrupt,
                          struct dump_as_interrupt_dump idump) {
  //printf("interruption : %w\n", &interrupt, 4);

  if (interrupt == 32) timer_isr();

  if (interrupt == 33) {
  	char x = ps2_ctrl_inb();
  	ps2_kbd_kmp_load(x);
  }
  if ((interrupt >= 32) && (interrupt < 48)) {
    pic_sendEOI(interrupt - 32);
  }
}
