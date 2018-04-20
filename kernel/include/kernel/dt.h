#ifndef _KERNEL_DTSET_H
#define _KERNEL_DTSET_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define GDT_SIZE 3
#define IDT_SIZE 256

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

void dt_init_gdt(void);
void dt_init_idt(void);
void dt_print_gdt(void);
void dt_print_idt(void);

#endif
