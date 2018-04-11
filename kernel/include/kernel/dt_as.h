#ifndef _KERNEL_DT_AS_H
#define _KERNEL_DT_AS_H

struct dt_ptr {
  uint16_t limit;
  uint32_t base;
} __attribut__((packed));

extern void dt_as_set_gdt(struct dt_ptr);
extern void dt_as_set_idt(struct dt_ptr);
extern void dt_as_reload_cs(void);

#endif
