#ifndef _KERNEL_MULTIBOOT_H
#define _KERNEL_MULTIBOOT_H

#include <stdint.h>
#include <stdbool.h>

struct flags_t {
  bool mem         : 1;
  bool boot_device : 1;
  bool cmdline     : 1;
  bool mods        : 1;
  bool syms_aout   : 1;
  bool syms_elf    : 1;
  bool mmap        : 1;
  bool drive       : 1;
  bool conf_tbl    : 1;
  bool bl_name     : 1;
  bool apm_tbl     : 1;
  bool vbe         : 1;
  bool framebuffer : 1;
  int unused       : 19;
};

struct mem_region_t {
  uint32_t size;
  uint64_t base;
  uint64_t len;
  uint32_t type;
} __attribute__((__packed__));

struct drive_t {
  uint32_t size;
  uint8_t  drive_number;
  uint8_t  drive_mode;
  uint16_t drive_cylinders;
  uint8_t  drive_heads;
  uint8_t  drive_sectors;
  uint16_t* io_ports;
} __attribute__((__packed__));

struct apm_tbl_t {
  uint16_t version;
  uint16_t cseg;
  uint32_t offset;
  uint16_t cseg_16;
  uint16_t dseg;
  uint16_t flags;
  uint16_t cseg_len;
  uint16_t cseg_16_len;
  uint16_t dseg_len;
} __attribute__((__packed__));

struct multiboot_info_t {
  struct flags_t flags;             // Flags indicating fields availables
  uint32_t mem_lower;               // Amount of memory available below 1M
  uint32_t mem_upper;               // Amount of memory available above 1M
  uint32_t boot_device;             // NOT USED
  char*    cmdline;                 // NOT USED
  uint32_t mods_count;              // NOT USED
  uint32_t mods_add;                // NOT USED
  uint32_t sym;                     // NOT USED
  struct mem_region_t* mmap_addr;   // Address of the memory map
  uint32_t mmap_len;                // Size of the memory map
  struct drive_t* drive_addr;       // Address of drives information
  uint32_t drive_len;               // Size of drive information
  uint32_t conf_tbl;                // NOT USED
  uint32_t boot_loader_name;        // NOT USED
  struct apm_tbl_t* apm_addr;       // Address of the apm table.
  void*    vbe_control_info;        // Addresses
  void*    vbe_mode_info;
  uint16_t vbe_mode;                // Video mode (VBE 3.0)
  uint16_t vbe_interface_seg;       // Self explainatory
  uint16_t vbe_interface_off;
  uint16_t vbe_interface_len;
  uint64_t*framebuffer_addr;        // Address of frame buffer
  uint32_t framebuffer_pitch;
  uint32_t framebuffer_width;
  uint32_t framebuffer_height;
  uint8_t  framebuffer_bpp;
  uint8_t  framebuffer_type;
  uint64_t color_info;
} __attribute__((__packed__));


#endif
