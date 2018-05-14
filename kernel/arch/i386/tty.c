#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>

#include "vga.h"

static unsigned char empty_char = 0x00;


void tty_initialize(void) {
  for (size_t i = 0; i < VGA_SIZE; i++) {
    term_buffer[i] = vga_entry(empty_char, VGA_COLOR_BLACK);
	}
}

void tty_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	term_buffer[index] = vga_entry(c, color);
}
