#ifndef _ALLOC_H
#define _ALLOC_H

#include <stddef.h>
#include <schtyp.h>

// These two variables represent where the part of the memory allocated to the
// heap. They are bound to disappear

#define HEAP_START ((void*) 0)
#define HEAP_END ((void*) 0x00100000)

// Now to the interesting part

void* malloc(size_t size);

void free(void* ptr);

#endif
