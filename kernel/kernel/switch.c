#include<kernel/switch.h>
#include<schtyp.h>
#include<proc.h>

static int curr_id = 0;

void switch(proc_id) {
  struct proc_t proc = proc_table[proc_id];
  *((uint32_t*) _PAGE_DIRECTORY + proc.dir_code) = 0x05;
  *((uint32_t*) _PAGE_DIRECTORY + proc.dir_stack) = 0x27;
  *((uint32_t*) _PAGE_DIRECTORY + proc.dir_heap) = 0x47;
};
