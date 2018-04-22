#include <stddef.h>
#include <string.h>

#include <cycle_array.h>

#define pos(ca) *((size_t*) ca)
#define len(ca) *((size_t*) ((char*) ca + sizeof(size_t)))
#define start(ca) ((char*) ca + 2 * sizeof(size_t))

int ca_get (void* dest, void* ca, size_t ind, size_t size) {
  size_t pos = pos(ca);
  size_t len = len(ca);
  char* start = start(ca);
  if ((ind + size) >= len) 
    return 1;
  size_t real_ind = pos + ind;
  if (real_ind >= len)
    real_ind -= len;
  if (real_ind + size < len) {
    memcpy((char*) dest, start + real_ind, size);
  } else {
    size_t mem_left = len - real_ind - 1;
    memcpy((char*) dest, start + pos, mem_left);
    ca_get ((char*) dest + mem_left, ca, (size_t) 0, size - mem_left);
  }
  return 0;
}
