#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>

void tty_initialize(void);
void tty_putentryat(unsigned char, uint8_t, size_t, size_t);
extern const size_t VGA_WIDTH;
extern const size_t VGA_HEIGHT;
extern const size_t VGA_SIZE;

uint16_t* const term_buffer;

#endif
