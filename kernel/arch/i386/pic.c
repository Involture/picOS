#include <kernel/pic.h>
#include <kernel/port.h>

void pic_sendEOI(unsigned char irq) {
  if (irq >= 8)
    outb(PIC2_COMMAND, PIC_EOI);
  outb(PIC1_COMMAND, PIC_EOI);
}

void pic_remap(int offset1, int offset2) {
  unsigned char a1, a2;
  a1 = inb(PIC1_DATA);                          // save masks
  a2 = inb(PIC2_DATA);

  outb(PIC1_COMMAND, ICW1_INIT + ICW1_ICW4);    // start the init seq ???
  outb(PIC2_COMMAND, ICW1_INIT + ICW1_ICW4);
  outb(PIC1_DATA, offset1);                     // setting vectors
  outb(PIC2_DATA, offset2);
  outb(PIC1_DATA, 4);                           // Tell master slave is IRQ2
  outb(PIC2_DATA, 2);                           // Tell slave its cascade id
  
  outb(PIC1_DATA, ICW4_8086);
  outb(PIC2_DATA, ICW4_8086);

  outb(PIC1_DATA, a1);                          // Restore saved mask
  outb(PIC2_DATA, a2);
}
