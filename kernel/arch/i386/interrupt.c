#include <stdio.h>

#include <kernel/dump.h>
#include <kernel/interrupt.h>

#include <kernel/ps2_kbd_kmp.h>

// GLOBAL FUNCTIONS

void interrupt_master_isr(struct dump_as_reg_dump rdump, uint32_t interrupt,
                          struct dump_as_interrupt_dump idump) {

  if ((interrupt >= 32) && (interrupt < 48)) {
  	char x = ps2_ctrl_inb();
    // printf("Data : %x\n", x);
  	ps2_kbd_kmp_load(x);
    pic_sendEOI(interrupt - 32);
  }
}
