#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <fifo.h>

#define in(fifo) *((size_t*) fifo)
#define out(fifo) *((size_t*) ((char*) fifo + sizeof(size_t)))
#define len(fifo) *((size_t*) ((char*) fifo + 2 * sizeof(size_t)))
#define empty(fifo) *((bool*) ((char*) fifo + 3 * sizeof(size_t)))
#define start(fifo) ((char*) fifo + 3 * sizeof(size_t) + sizeof(bool))

int fifo_enqueue(void* fifo, uint8_t byte) {
  size_t in = in(fifo);
  char* start = start(fifo);
  if (in == out(fifo)) {
    if (empty(fifo)) {
      empty(fifo) = false;
    } else {
      return 1;
    };
  }
  *(start + in) = byte;
  size_t new_in = in + 1;
  if (new_in == len(fifo))
    new_in = 0;
  return 0;
}
    
