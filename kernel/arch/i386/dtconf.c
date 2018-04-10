#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <kernel/dt.h>

#define GDT_SIZE 3

uint64_t picOS_gdt[GDT_SIZE] = {0};

static struct gdt_entry gdt_abstr[GDT_SIZE] = {
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

void initialize_gdt(void) {
  make_gdt(picOS_gdt, gdt_abstr, GDT_SIZE);
  set_gdt(picOS_gdt, sizeof(picOS_gdt));
};
