#ifndef _KERNEL_PIT_H
#define _KERNEL_PIT_H

#define PIT_DATA_PORT 0x40
#define PIT_CMD_PORT 0x43

void pit_init(void);

#endif
