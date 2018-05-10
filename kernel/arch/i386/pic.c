#include <stdint.h>
#include <kernel/pic.h>
#include <kernel/port.h>

#define PIC1          0x20        // IO base address for master PIC
#define PIC2          0xA0        // IO base address for slave PIC
#define PIC1_COMMAND  PIC1
#define PIC1_DATA     (PIC1 + 1)
#define PIC2_COMMAND  PIC2
#define PIC2_DATA     (PIC2 + 1)

#define PIC_EOI       0x20        // End of Interrupt command

#define ICW1_ICW4         0x01    // ICW4 (not) needed
#define ICW1_SINGLE       0x02    // Single (cascade) mode
#define ICW1_INTERVAL4    0x04    // Call address interval 4 (8)
#define ICW1_LEVEL        0x08    // Level triggered (edge) mode
#define ICW1_INIT         0x10    // Initialization required

#define ICW4_8086         0x01    // 8086/88 mode
#define ICW4_AUTO         0x02    // Auto (normal) EOI
#define ICW4_BUF_SLAVE    0x08    // Buffered mode/slave
#define ICW4_BUF_MASTER   0x0C    // Buffered mode/master
#define ICW4_SFNM         0x10    // Special fully nested (not)

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
