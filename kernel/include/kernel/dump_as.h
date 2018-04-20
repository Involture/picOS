#ifndef _KERNEL_DUMP_AS_H
#define _KERNEL_DUMP_AS_H

#include <stdint.h>
#include <stddef.h>

struct dump_as_interrupt_dump {
  uint32_t error_code;
  uint32_t eip;
  uint32_t cs;
  uint32_t eflags;
} __attribute__((packed));

struct dump_as_reg_dump {
  uint32_t edi;
  uint32_t esi;
  uint32_t ebp;
  uint32_t esp;
  uint32_t edx;
  uint32_t ecx;
  uint32_t ebx;
  uint32_t eax;
} __attribute__((packed));

struct dump_as_seg_dump {
  uint8_t cs;
  uint8_t ds;
  uint8_t es;
  uint8_t fs;
  uint8_t gs;
  uint8_t ss;
} __attribute__((packed));

extern void dump_as_reg(struct dump_as_reg_dump*);
extern void dump_as_seg(struct dump_as_seg_dump*);
extern void dump_as_stack(uint32_t*, size_t);

#endif
