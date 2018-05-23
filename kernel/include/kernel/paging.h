#ifndef _KERNEL_PAGING_H
#define _KERNEL_PAGING_H

#include <stdbool.h>

/* Page directory entry structure
 
   0 | 1 | 2 | 3 | 4 | 5 |   6   | 7 | 8 |  9-11  |       12-31
   P | R | U | W | C | A | unset | S | G | unused | Page table address

   Page directory entry structure
 
   0 | 1 | 2 | 3 | 4 | 5 | 6 |   7   | 8 |  9-11  |         12-31
   P | R | U | W | C | A | D | unset | G | unused | Physical page address

   More documentation at wiki.osdev.org/Paging

 */

struct page_entry {
  bool P            : 1;
  bool R            : 1;
  bool U            : 1;
  bool W            : 1;
  bool C            : 1;
  bool A            : 1;
  bool D            : 1;
  bool S            : 1;
  bool G            : 1;
  uint8_t unused    : 3;
  uint32_t physaddr : 20;
};

#endif
