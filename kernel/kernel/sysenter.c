#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <kernel/sysenter.h>
#include <task.h>

#include <kernel/sysenter.h>

void sysenter_master_handler(uint16_t code, uint32_t esp, uint32_t eip, 
                            void* data, size_t data_size) {
  puts("Im the master syscall handler !");
  printf("  code : %x\n", code);
  printf("  data size : %x", data_size);
  for (size_t i = 0; i < data_size; i++) {
    printf("  data %x : %x\n", i, *((uint8_t*) data + i));
  }

  task_data_t test_data1;
  task_data_t test_data2;
  uint32_t data1 = 0xCAFEBABE;
  char data2[] = "Coucou, c'est le kernel, j'ai recu entendu ton appel.";
  test_data1.ptr = &data1;
  test_data2.ptr = data2;
  test_data1.size = sizeof(data1);
  test_data1.size = sizeof(data2);

  sysreturn(eip, esp, &test_data1);
  assert(returned);
  sysexit();
}
