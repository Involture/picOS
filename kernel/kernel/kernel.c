#include <stdio.h>
#include <kernel/tty_ext.h>
#include <kernel/dt.h>
#include <kernel/cpuid.h>
#include <kernel/pic.h>

void kernel_main(void) {
	tty_ext_initialize();
  initialize_gdt();
  reload_cs();
  set_cpuid();
  pic_remap(32, 40);
  for (size_t i = 0; i < 4; i++)
    printf("||%x ", *((char*) cpuid + i));
  while(1);
}
