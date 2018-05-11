#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include <kernel/tty.h>
#include <kernel/tty_ext.h>
#include <stdio.h>

#include "vga.h"

static unsigned char empty_char = 0x00;

static const size_t HISTORY_LINES = 50 * 25;
static const size_t HISTORY_SIZE = 50 * 25 * 80;
static const int16_t MAX_SCREEN_OFS = 49 * 25;
static const int16_t MIN_SCREEN_OFS = -49;

static size_t term_column;
static uint8_t term_color;
static int16_t screen_ofs;

static uint16_t history[50 * 25 * 80];

/* Cyclique history vector internal management*/

static void termcpy(uint16_t* dstptr, const uint16_t* srcptr, size_t size) {
  memcpy(dstptr, srcptr, size * sizeof(uint16_t));
}

static void linecpy(uint16_t* dstptr, const uint16_t* srcptr, size_t nline) {
  termcpy(dstptr, srcptr, nline * VGA_WIDTH);
}

static size_t history_line_pos;

static void add_history(uint16_t entry) {
  history[history_line_pos * VGA_WIDTH + term_column] = entry;
}

static void history_add_line(void) {
  if (++history_line_pos == HISTORY_LINES)
    history_line_pos = 0;
}

/* Requires : ofs + VGA_HEIGHT - 1 < HISTORY_LINES */
static void get_screen(uint16_t* destbuf, int16_t ofs) {
  size_t lines_left;
  size_t nlines_to_copy =
    (ofs > 0) ? VGA_HEIGHT : (VGA_HEIGHT + ofs);
  size_t start_pos = history_line_pos;
  if (ofs + VGA_HEIGHT - 1 > history_line_pos)
    start_pos += HISTORY_LINES;
  start_pos -= ofs + VGA_HEIGHT - 1;
  lines_left = HISTORY_LINES - start_pos - 1;
  if (lines_left < nlines_to_copy) {
    linecpy(destbuf, history + start_pos * VGA_WIDTH, lines_left);
    linecpy(destbuf + lines_left * VGA_WIDTH, 
            history, nlines_to_copy - lines_left);
  }
  else {
    linecpy(destbuf, history + start_pos * VGA_WIDTH,
            nlines_to_copy);
  };
  memset(destbuf + nlines_to_copy * VGA_WIDTH, 0, 
         (VGA_HEIGHT - nlines_to_copy) * VGA_WIDTH * sizeof(uint16_t));
}

/* History private functions */

static void retreive_history(void) {
  get_screen(term_buffer, screen_ofs);
}

/* Handling special characters */

static void new_line(void) {
  tty_ext_putchar(empty_char);
  while (term_column != 0)
    tty_ext_putchar(empty_char);
};

static bool handle_special_char(unsigned char ic) {
  switch (ic) {
    case '\n':
      new_line();
      break;
    default:
      return false;
  };
  return true;
};

/* Extern functions */

void tty_ext_initialize(void) {
  tty_initialize();
  history_line_pos = 24; 
  screen_ofs = 0;
  term_column = 0;
  term_color = vga_entry_color(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
  for (size_t i = 0; i < HISTORY_SIZE; i++) {
    history[i] = vga_entry(empty_char, term_color);
  };
}

  /* Browsing */

void tty_ext_go_up(size_t ofs) {
  int8_t new_screen_ofs = screen_ofs + (int8_t) ofs;
  screen_ofs = 
    (new_screen_ofs < MAX_SCREEN_OFS) ? new_screen_ofs : MAX_SCREEN_OFS;
  retreive_history(); 
}

void tty_ext_go_down(size_t ofs) {
  int8_t new_screen_ofs = screen_ofs - (int8_t) ofs;
  screen_ofs = 
    (new_screen_ofs > MIN_SCREEN_OFS) ? new_screen_ofs : MIN_SCREEN_OFS;
  retreive_history(); 
}

void tty_ext_scroll_up(void) {
  tty_ext_go_up(1);
}

void tty_ext_scroll_down(void) {
  tty_ext_go_down(1);
}

  /* Wrinting */

void tty_ext_set_color(uint8_t color) {
  term_color = color;
}

void tty_ext_putchar(char c) {
  unsigned char ic = (unsigned char) c;
  if (handle_special_char(ic))
    return;
  uint16_t entry = vga_entry(ic, term_color);
  size_t term_row = VGA_HEIGHT - 1 + screen_ofs;
  term_buffer[term_column + term_row * VGA_WIDTH] = entry;
  add_history(entry);
	if (++term_column == VGA_WIDTH) {
		term_column = 0;
    history_add_line();
    screen_ofs++;
    if ((screen_ofs <= 1) | (screen_ofs == MAX_SCREEN_OFS))
      tty_ext_scroll_down();
	};
}

void tty_ext_rm_last_char(void) {
  size_t term_row = VGA_HEIGHT - 1 + screen_ofs;

  if (term_column == 0) {
    tty_ext_scroll_up();
    term_column = VGA_WIDTH - 1;
    screen_ofs = screen_ofs - 1;    
    term_buffer[term_column + term_row * VGA_WIDTH] = vga_entry(empty_char, term_color);

    while (term_column > 0 && term_buffer[term_column - 1 + term_row * VGA_WIDTH] == vga_entry(empty_char, term_color)) {
      term_column -= 1;
    }

    if (history_line_pos == 0) {
      history_line_pos = HISTORY_LINES - 1;
    } else {
      history_line_pos -= 1;
    }
  } else {
    term_column -= 1;
    term_buffer[term_column + term_row * VGA_WIDTH] = empty_char;
  }

  // what about the history ?
  history[history_line_pos * VGA_WIDTH + term_column] = NULL;
}

void tty_ext_write(const char* data, size_t size) {
  for (size_t i = 0; i < size; i++)
    tty_ext_putchar(data[i]);
}

void tty_ext_write_string(const char* data) {
  tty_ext_write(data, strlen(data));
}
