#include <stddef.h>
#include <string.h>

#include <cycle_array.h>

#define pos(ca) *((size_t*) ca)
#define len(ca) *((size_t*) ((char*) ca + sizeof(size_t)))
#define start(ca) ((char*) ca + 2 * sizeof(size_t))

void ca_append (void* ca, const void* src, size_t size) {
  size_t pos = pos(ca);
  size_t len = len(ca);
  char* start = start(ca);
  if (size < (len - pos)) {
    memcpy(start + pos, (const char*) src, size);
    pos(ca) = ((pos + size == len) ? 0 : (pos + size));
  } else {
    size_t mem_left = len - pos - 1;
    memcpy(start + pos, (const char*) src, mem_left);
    pos(ca) = 0;
    ca_append (ca, (const char*) src + mem_left, size - mem_left);
  }
}
