#include <stdio.h>
#include <kernel/dump_as.h>
#include <kernel/pic.h>
#include <kernel/ps2_ctrl.h>

#include <kernel/interrupt.h>

void interrupt_master_isr(struct dump_as_reg_dump rdump, uint32_t interrupt,
                          struct dump_as_interrupt_dump idump) {
  printf("Interrupt : %x | Errcode : %w\n", interrupt,
         &(idump.error_code), 4);
  rdump = rdump;

  if ((interrupt >= 32) && (interrupt < 48)) {
    printf("Data : %x\n", ps2_ctrl_inb());
    pic_sendEOI(interrupt - 32);
  }
}
