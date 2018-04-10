#include <stdio.h>
#include <kernel/tty_ext.h>
#include <kernel/dt.h>
#include <kernel/cpuid.h>
#include <kernel/pic.h>
#include <kernel/ps2_ctrl.h>

void kernel_main(void) {
	tty_ext_initialize();
  dt_init_gdt();
  dt_reload_cs();
  dt_init_idt();
  cpuid_set();
  if (cpuid_has_feat(CPUID_FEAT_EDX_APIC))
    pic_disable_apic();
  pic_remap(32, 40);
  if (ps2_ctrl_init() != 0)
    puts("Oops, something wrong happened with ps2 controller initialization");
  while(1);
}
