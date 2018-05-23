#ifndef _KERNEL_PAGING_H
#define _KERNEL_PAGING_H

#include <stdbool.h>

struct paging_dir_desc {
  bool write_enable   : 1;
  bool user_access    : 1;
  bool write_through  : 1;
  bool cache_disabled : 1;
  bool accessed       : 1;
  bool present        : 1;
  bool always_zero    : 1;
  bool big_pages      : 1;
  int avail           : 3;
  int page_table_addr : 20;
};

struct paging_page_desc {
  bool present        : 1;
  bool write_enable   : 1;
  bool user_access    : 1;
  bool write_through  : 1;
  bool cache_disabled : 1;
  bool accessed       : 1;
  bool dirty          : 1;
  bool always_zero    : 1;
  bool global         : 1;
  int avail           : 2;
  int page_phys_addr  : 20;
};

struct paging_dir_desc* paging_directories;
struct paging_page_desc* paging_pages;
 
void paging_init(void);

#endif
