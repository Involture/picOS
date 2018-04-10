#include <stdio.h>
#include <stdint.h>
#include <kernel/tty_ext.h>
#include <kernel/dt.h>
#include <kernel/cpuid.h>
#include <kernel/pic.h>
#include <kernel/ps2_ctrl.h>
#include <kernel/ps2_driver.h>

void kernel_init(void) {
  /* The current goal is to make this sequence work 
     Let's put a lot of prints to ensure this :p
  */
	tty_ext_initialize();

  dt_init_gdt();
  dt_print_gdt();
  
  dt_reload_cs();
  uint32_t* seg = dt_drop_seg();
  printf("Segment drop : %w\n", seg, 16);

  dt_init_idt();
  dt_print_idt();
  dt_raise();

  printf("Initial cpuid : %w\n", cpuid, 4);
  cpuid_set();
  printf("After setting cpuid : %w\n", cpuid, 4);

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
