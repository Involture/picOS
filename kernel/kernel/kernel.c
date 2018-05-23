#include <stdio.h>
#include <stdint.h>
#include <kernel/multiboot.h>
#include <kernel/tty_ext.h>
#include <kernel/dt.h>
#include <kernel/cpuid.h>
#include <kernel/pic.h>
#include <kernel/port.h>
#include <kernel/ps2_ctrl.h>
#include <kernel/interrupt.h>
#include <kernel/dump.h>
#include <kernel/sysenter.h>
#include <kernel/ps2_kbd_kmp.h>
#include <schtyp.h>
#include <syscall.h>
#include <proc.h>
#include <syscalls/proc.h>
#include <kernel/pit.h>
#include <kernel/filesystem.h>

void kernel_init(void) {
  tty_ext_initialize();

  dt_init_gdt();
  //dt_print_gdt();

  dt_init_idt();
  //dt_print_idt();

  cpuid_set();
  // step 0
  printf("cpuid : %w\n", cpuid, 4);

  pic_remap(32, 40, 0xFFFC);
  interrupt_enable();

  // step 1
  // kernel/arch/i386/ps2_ctrl.c
  ps2_ctrl_init();


  sysenter_init();
  // pit_init();
  filesystem_init();
}

void kernel_main(struct multiboot_info_t* grub_info) {
  multiboot_info = *grub_info;
  kernel_init();
  puts("Init sequence ended");
  printf("  high_memory : %w\n", &(multiboot_info.mem_upper), 4);

  // ok until now
  while(1);
  // step 2
  // kernel/arch/i386/interrupt.c
}
