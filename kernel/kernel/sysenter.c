#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <kernel/sysenter.h>
#include <task.h>

#include <kernel/sysenter.h>

void sysenter_master_handler(uint16_t code, uint32_t return_esp, 
                             uint32_t return_eip, struct data_t* data) {
  struct data_t test_data2;
  char data2[] = "Coucou, c'est le kernel, j'ai recu ton appel.";
  test_data2.ptr = data2;
  test_data2.size = sizeof(data2);

  sysreturn(return_eip, return_esp, &test_data2);
  assert(returned);
  sysexit();
}
