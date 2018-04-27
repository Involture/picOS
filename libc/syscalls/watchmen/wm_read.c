#include <syscall.h>
#include <stdint.h>

#include <syscalls/watchmen.h>

uint8_t wm_read(uint16_t offset) {
  return *((uint8_t*) syscall(SYSCALL_WATCHMEN_READ, &offset, sizeof(offset)));
}
