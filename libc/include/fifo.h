#ifndef _FIFO_H
#define _FIFO_H

#include <stddef.h>
#include <stdint.h>

int fifo_mk(void*, size_t);
int fifo_enqueue(void*, uint8_t);
char fifo_dequeue(void*);
bool fifo_is_empty(void*);

#endif
