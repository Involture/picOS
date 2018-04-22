#include <stddef.h>
#include <stdbool.h>

#include <fifo.h>
#include <cycle_array.h>

#define in(fifo) *((size_t*) fifo)
#define out(fifo) *((size_t*) ((char*) fifo + sizeof(size_t)))
#define len(fifo) *((size_t*) ((char*) fifo + 2 * sizeof(size_t)))
#define empty(fifo) *((bool*) ((char*) fifo + 3 * sizeof(size_t)))
#define start(fifo) ((char*) fifo + 3 * sizeof(size_t) + sizeof(bool))

int fifo_mk(void* mem, size_t size) {
  if (size <= 3 * sizeof(size_t) + sizeof(bool))
    return 1;
  in(mem) = (size_t) 0;
  out(mem) = (size_t) 0;
  len(mem) = size - (3 * sizeof(size_t) + sizeof(bool));
  empty(mem) = true;
  return 0;
}
