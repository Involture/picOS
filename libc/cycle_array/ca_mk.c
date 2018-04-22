#include <stddef.h>

#include <cycle_array.h>

#define pos(ca) *((size_t*) ca)
#define len(ca) *((size_t*) ((char*) ca + sizeof(size_t)))
#define start(ca) ((char*) ca + 2 * sizeof(size_t))

int ca_mk (void* mem, size_t size) {
  if (size < 3 * sizeof(size_t))
    return 1;
  pos(mem) = (size_t) 0;
  len(mem) = size - (size_t) 2 * sizeof(size_t);
  return 0;
}
