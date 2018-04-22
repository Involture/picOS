#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <fifo.h>

#define in(fifo) *((size_t*) fifo)
#define out(fifo) *((size_t*) ((char*) fifo + sizeof(size_t)))
#define len(fifo) *((size_t*) ((char*) fifo + 2 * sizeof(size_t)))
#define empty(fifo) *((bool*) ((char*) fifo + 3 * sizeof(size_t)))
#define start(fifo) ((char*) fifo + 3 * sizeof(size_t) + sizeof(bool))

char fifo_dequeue(void* fifo) {
  if (empty(fifo))
    return 0;
  size_t out_byte = *(start(fifo) + out(fifo));
  size_t new_out = out(fifo) + 1;
  if (new_out == len(fifo))
    new_out = 0;
  out(fifo) = new_out;
  if (new_out == in(fifo))
    empty(fifo) = true;
  return out_byte;
}
