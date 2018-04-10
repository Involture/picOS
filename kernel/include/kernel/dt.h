#ifndef _KERNEL_DTSET_H
#define _KERNEL_DTSET_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

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
void make_gdt(uint64_t*, struct gdt_entry*, size_t);

extern void initialize_gdt(void);
extern void set_gdt(uint64_t* gdt_ptr, size_t size);
extern void initialize_gdt(void);
extern void reload_cs(void);
#endif
