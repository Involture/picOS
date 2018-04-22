#include <stddef.h>
#include <stdbool.h>

#include <fifo.h>

#define empty(fifo) *((bool*) ((char*) fifo + 3 * sizeof(size_t)))

bool fifo_is_empty(void* fifo) {
  return empty(fifo);
}
