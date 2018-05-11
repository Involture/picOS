#include <schtyp.h>
#include <watchmen.h>
#include <syscall.h>
#include <syscalls/watchmen.h>

uint8_t wm_read(uint16_t offset) {
  struct data_t td;
  td.ptr = &offset;
  td.size = sizeof(offset);
  return *((uint8_t*) 
           (syscall(SYSCALL_WATCHMEN_READ, &td)->ptr)
          );
}
