#ifndef _KERNEL_DTCONF_H
#define _KERNEL_DTCONF_H

#include <stdbool.h>
#include <stdint.h>

#define GDT_SIZE 5
#define IDT_SIZE 256

// An entry for the gdt. Bits need to be reordered to produce an entry readable
// by the preocessor.
struct gdt_entry {
  uint32_t base;  // Base address for the segment
  uint32_t limit; // Limit of the segment
                  // times 4kib otherwise.
  bool prs;       // Set if sector is physicaly present
  uint8_t privl;  // Ring permission to go to segment (see dc)
  bool ex;        // Set if the segment can be executed
  bool dc;        // For data segment (ex = 0) : if set the segment grows down
                  // For code segment : if 0 : ring must be equal to privl
                  //                    if 1 : ring must be >= to privl
  bool rw;        // For data segment : if set enable write access
                  // For code segment : if set enable read access
  bool ac;        // Cpu set this to 1 when the segment is loaded
  bool gr;        // Granularity. If set limit is multiplied by 0x400.
  bool sz;        // if set, sector in 32 bit else sector in 16 bit.
};

// Same thing for idt.
enum idt_gate_type {
  IDT_GATE_TYPE_TASK      = 0x5,
  IDT_GATE_TYPE_INTERRUPT = 0xE,
  IDT_GATE_TYPE_TRAP      = 0xF,
};

struct idt_entry {
  uint16_t selector;        // Segment selector containing the I handler code
  uint32_t offset;          // Offset of the ISR in the segment
  enum idt_gate_type type;  // Type of gate
  uint8_t dpl;              // Descriptor privilege level
  bool prs;                 // Disable if interrupt not used
};

extern struct gdt_entry gdt_conf[];
extern struct idt_entry idt_conf[];

void dtconf_init(void);

#endif
