#include <stdio.h>
#include <stdint.h>
#include <kernel/tty_ext.h>
#include <kernel/dt.h>
#include <kernel/cpuid.h>
#include <kernel/pic.h>
#include <kernel/port.h>
#include <kernel/ps2_ctrl.h>
#include <kernel/interrupt.h>
#include <kernel/dump.h>

void kernel_init(void) {
	tty_ext_initialize();

  dt_init_gdt();
  dt_print_gdt();
  dt_reload_cs();

  dt_configure_idt();
  dt_init_idt();
  dt_print_idt();

  cpuid_set();
  printf("After setting cpuid : %w\n", cpuid, 4);

  dt_raise();
  puts("Interrupt test passed \\o/");
  while(1);

  if (cpuid_has_feat(CPUID_FEAT_EDX_APIC))
    pic_disable_apic();
  pic_remap(32, 40);

  //ps2_ctrl_init(); Will be verified later
}

void kernel_main(void) {
  kernel_init();
  scan_code_detection();
  while(1);
}
