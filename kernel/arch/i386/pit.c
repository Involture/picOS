#include <kernel/port.h>

#include <kernel/pit.h>

void pit_init(void) {
  outb(PIT_CMD_PORT, 0x34);
  outb(PIT_DATA_PORT, 0xA9);
  outb(PIT_DATA_PORT, 0x04);
}
