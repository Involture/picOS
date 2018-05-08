#include <stdio.h>
#include <stdlib.h>

void panic(void) {
#if defined(__is_libk)
	printf("kernel panic !\n");
#else
	printf("panic()\n");
#endif
	while (1) { }
	__builtin_unreachable();
}
