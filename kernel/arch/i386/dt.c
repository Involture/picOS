#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <kernel/dtconf.h>
#include <kernel/interrupt_as.h>
#include <kernel/dt_as.h>

#include <kernel/dt.h>

static uint64_t picOS_gdt[GDT_SIZE] = {0};
static uint64_t picOS_idt[IDT_SIZE] = {0};

/* To understand the following, please refer to GDT entry layout.
It consists of distributing the bits of the previous structure over 8 bytes
in a complex way for compatibility with i286 processors */
static uint64_t make_gdt_entry(struct gdt_entry source) {
  uint8_t access = (uint8_t) 0x00;
  access |= source.ac           & (uint8_t) 0x01;
  access |= (source.rw    << 1) & (uint8_t) 0x02;
  access |= (source.dc    << 2) & (uint8_t) 0x04;
  access |= (source.ex    << 3) & (uint8_t) 0x08;
  access |=                       (uint8_t) 0x10;
  access |= (source.privl << 5) & (uint8_t) 0x60;
  access |= (source.prs   << 7) & (uint8_t) 0x80;

  uint8_t flags = (uint8_t) 0x0; // 4 bits long in practice
  flags  |= (source.sz    << 2) & (uint8_t) 0x4;
  flags  |= (source.gr    << 3) & (uint8_t) 0x8;
  
  uint64_t access64 = (uint64_t) access;
  uint64_t flags64 = (uint64_t) flags;
  uint64_t base64 = (uint64_t) source.base;
  uint64_t limit64 = (uint64_t) source.limit;

  uint64_t result = (uint64_t) 0x0000000000000000;
  result |= limit64          & (uint64_t) 0x000000000000FFFF;
  result |= (base64   << 16) & (uint64_t) 0x00000000FFFF0000;
  result |= (base64   << 16) & (uint64_t) 0x000000FF00000000;
  result |= (access64 << 40) & (uint64_t) 0x0000FF0000000000;
  result |= (limit64  << 32) & (uint64_t) 0x000F000000000000;
  result |= (flags64  << 52) & (uint64_t) 0x00F0000000000000;
  result |= (base64   << 32) & (uint64_t) 0xFF00000000000000;

  return result;
}

/* Same, refer to IDT entry layout */
static uint64_t make_idt_entry(struct idt_entry source) {
  uint8_t type_attr = (uint8_t) 0x00;
  type_attr |= source.type                                & 0x0F;
  type_attr |= (source.dpl                          << 5) & 0x60;
  type_attr |= ((source.type == IDT_GATE_TYPE_TASK) << 4) & 0x10;
  type_attr |= (source.prs                          << 7) & 0x80;
  
  uint64_t type_attr64 = (uint64_t) type_attr;
  uint64_t selector64 = (uint64_t) source.selector;
  uint64_t offset64 = (uint64_t) source.offset;

  uint64_t result = (uint64_t) 0x0000000000000000;
  result |= offset64                & 0x000000000000FFFF;
  result |= (selector64  << 16)     & 0x00000000FFFF0000;
  result |= (type_attr64 << 40)     & 0x0000FF0000000000;
  result |= (offset64    << 32)     & 0xFFFF000000000000;

  return result;
}

static void make_gdt(uint64_t* dest, struct gdt_entry* source, size_t size) {
  for (size_t i = 0; i < size; i++)
    dest[i] = make_gdt_entry(source[i]);
}

static void make_idt(uint64_t* dest, struct idt_entry* source, size_t size) {
  for (size_t i = 0; i < size; i++)
    dest[i] = make_idt_entry(source[i]);
}

void print_dt(uint64_t* dt, size_t size) {
  for (size_t i = 0; i < size; i++)
    printf("dt_entry %x : %w\n", i, dt + i, 8);
};

void dt_print_gdt(void) {
  puts("Printing generated gdt :");
  print_dt(picOS_gdt, GDT_SIZE);
}

void dt_print_idt(void) {
  puts("Printing generated idt :");
  print_dt(picOS_idt, 10);
}

void dt_init_gdt(void) {
  make_gdt(picOS_gdt, gdt_conf, GDT_SIZE);
  struct dt_ptr ptr = {.limit = sizeof(picOS_gdt), 
                       .base = (uint32_t) picOS_gdt
                      };
  dt_as_set_gdt(ptr);
};

void dt_init_idt(void) {
  make_idt(picOS_idt, idt_conf, IDT_SIZE);
  struct dt_ptr ptr = {.limit = sizeof(picOS_idt), 
                       .base = (uint32_t) picOS_idt
                      };
  dt_as_set_idt(ptr);
};
