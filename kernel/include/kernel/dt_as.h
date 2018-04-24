#ifndef _KERNEL_DT_AS_H
#define _KERNEL_DT_AS_H

// Describe a descriptor table. Argument for lidt and lgdt instructions
struct dt_ptr {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed));

// Self explainatory
extern void dt_as_set_gdt(struct dt_ptr);
extern void dt_as_set_idt(struct dt_ptr);
// Reload the segments from the gdt after setting it
extern void dt_as_reload_cs(void);

#endif
