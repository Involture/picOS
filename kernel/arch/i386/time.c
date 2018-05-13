#include <stdio.h>
#include <stdbool.h>

#include <kernel/time.h>

unsigned long long ms_counter = 0;
unsigned long long s_counter = 0;

void timer_isr(void) {
  static bool correction_needed = false;
  if (correction_needed) {
    correction_needed = false;
  } 
  else if (ms_counter++ == 6566) {
    correction_needed = true;
  }
  if ((ms_counter % 1000) == 0) {
    s_counter = ms_counter / 1000;
    printf("Time %w\n", &s_counter, 8);
  }
}
