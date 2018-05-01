#ifndef _KERNEL_TTY_EXT_H
#define _KERNEL_TTY_EXT_H

#include <stddef.h>
#include <stdint.h>

void tty_ext_initialize(void);

/* Browsing */
void tty_ext_go_up(size_t);
void tty_ext_go_down(size_t);
void tty_ext_scroll_up(void);
void tty_ext_scroll_down(void);

/* Writing */
void tty_ext_set_color(uint8_t);
void tty_ext_putchar(char);
void tty_ext_write(const char*, size_t);
void tty_ext_write_string(const char*);

/* Deleting */
void tty_ext_rm_last_char(void);

#endif
