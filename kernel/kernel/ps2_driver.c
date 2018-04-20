#include <kernel/ps2_ctrl.h>
#include <stdio.h>
#include <stdint.h>

#include <kernel/ps2_driver.h>

char scan_code = 0;
uint64_t timer = 0;

void scan_code_detection(void) {
}
