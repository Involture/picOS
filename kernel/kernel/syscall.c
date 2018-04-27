#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#include <syscall.h>

void syscall_master_handler(size_t code, void* data, size_t data_size) {
  puts("Im the master syscall handler !");
  printf("  code : %x\n", code);
  for (size_t i = 0; i < data_size; i++) {
    printf("  data %x : %x\n", i, *((uint8_t*) data + i));
  }
}
