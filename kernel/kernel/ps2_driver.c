#include <kernel/ps2_ctrl.h>
#include <stdio.h>
#include <stdint.h>

#include <kernel/ps2_driver.h>
/*
For the moment, we will implement polling as interrupts and ps2 controller are
not ready for IRQ driven keyboard !!!

We are simply going to design a tool to determine scan codes
*/

#define TIMEOUT 100000000

char scan_code = 0;
uint64_t timer = 0;

void scan_code_detection(void) {
  char new_scan_code;
  while (timer < TIMEOUT) {
    timer = 0;
    while (((new_scan_code = ps2_ctrl_inb()) == scan_code) & 
           (timer < TIMEOUT))
      timer++;
    scan_code = new_scan_code;
    printf("Scancode : %x\n", scan_code);
  };
  puts("Exiting");
}
