#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <kernel/dt.h>

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

void make_gdt(uint64_t* dest, struct gdt_entry* source, size_t size) {
  for (size_t i = 0; i < size; i++)
    dest[i] = make_gdt_entry(source[i]);
}


