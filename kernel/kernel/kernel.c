#include <stdio.h>
#include <kernel/tty_ext.h>

void kernel_main(void) {
	tty_ext_initialize();
  char i = 0;
  while(1) {
    i++;
    printf("hey, salut ! : %c", i);
  };
}
