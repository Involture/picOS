#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>

#define VGA_WIDTH   80
#define VGA_HEIGHT  25
#define VGA_SIZE    ( VGA_WIDTH * VGA_HEIGHT )
#define TERM_BUFFER ((uint16_t*) 0xB8000)

void tty_initialize(void);
void tty_putentryat(unsigned char, uint8_t, size_t, size_t);

uint16_t* const term_buffer;

#endif
