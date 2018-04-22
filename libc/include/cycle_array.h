#ifndef _CYCLE_ARRAY_H
#define _CYCLE_ARRAY_H

#include <stddef.h>

int ca_mk(void*, size_t);
void ca_append(void*, const void*, size_t);
int ca_change(void*, const void*, size_t, size_t);
int ca_get(void*, void*, size_t, size_t);

#endif
