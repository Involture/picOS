#include <stdint.h>
#include <kernel/pic.h>
#include <kernel/port.h>

void pic_sendEOI(unsigned char irq) {
  if (irq >= 8)
    outb(PIC2_COMMAND, PIC_EOI);
  outb(PIC1_COMMAND, PIC_EOI);
}

void pic_remap(uint32_t offset1, uint32_t offset2, uint16_t mask) {
  outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);    // start the init seq ???
  outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
  outb(PIC1_DATA, offset1);                     // setting vectors
  outb(PIC2_DATA, offset2);
  outb(PIC1_DATA, 4);                           // Tell master slave is IRQ2
  outb(PIC2_DATA, 2);                           // Tell slave its cascade id
  
  outb(PIC1_DATA, ICW4_8086);
  outb(PIC2_DATA, ICW4_8086);


  uint8_t master_mask = (uint8_t) (mask & 0xFF);
  uint8_t slave_mask = (uint8_t) ((mask & 0xFF00) >> 4);
  outb(PIC1_DATA, master_mask);                 // set masks
  outb(PIC2_DATA, slave_mask);
}
