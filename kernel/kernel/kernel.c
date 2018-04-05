/* Not available as the standard library is not used yet
  
#include <stdio.h>
*/

#include <kernel/tty.h>

void kernel_main(void) {
	terminal_initialize();
	terminal_write("Hello, kernel World!\n", 21);
}
