#include <kernel/dt.h>
#include <kernel/int.h>
#include <stdbool.h>

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

struct idt_entry idt_conf[IDT_SIZE] = {
    {.selector = 0x08,
     .offset = (uint32_t) &isr_wrapper,
     .type = IDT_GATE_TYPE_INTERRUPT,
     .dpl = 0,
     .prs = true,
    },
  };
