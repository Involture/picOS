#include <kernel/dt.h>

struct gdt_entry gdt_conf[GDT_SIZE] = {
  {},
  {.limit = 0xFFFFFFFF,
   .prs   = true,
   .ex    = true,
   .dc    = true,
   .rw    = true,
   .gr    = true,
   .sz    = true
  },
  {.limit = 0xFFFFFFFF,
   .prs   = true,
   .rw    = true,
   .gr    = true,
   .sz    = true
  }
};

struct idt_entry idt_conf[IDT_SIZE] = {0};
