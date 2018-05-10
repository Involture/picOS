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
#include <kernel/sysenter.h>
#include <syscall.h>

#include <kernel/ps2_kbd_kmp.h>

void kernel_init(void) {
  tty_ext_initialize();

  dt_init_gdt();
  //dt_print_gdt();

  dt_init_idt();
  //dt_print_idt();

  cpuid_set();
  // step 0
  printf("cpuid : %w\n", cpuid, 4);

  pic_remap(32, 40, 0xFFFD);
  interrupt_enable();

  // step 1
  // kernel/arch/i386/ps2_ctrl.c
  ps2_ctrl_init();
  sysenter_init();

  uint32_t data = 0xFAFABEBE;
  struct task_data_t td;
  td.ptr = &data;
  td.size = sizeof(data);

  volatile struct task_data_t* returned_data;
  returned_data = syscall(0xBABE, &td);
  printf("Returned data size : %x\n", returned_data->size);
  printf("Data : %w\n", returned_data->ptr, returned_data->size);
}

void kernel_main(void) {
  kernel_init();
  puts("Init sequence ended");
  // ok until now
  ps2_clear();
  while(1);
  ps2_ctrl_timeout = -1;
  // step 2
  // kernel/arch/i386/interrupt.c
}

