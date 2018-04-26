#ifndef _SYSCALL_H
#define _SYSCALL_H

#include <stddef.h>
#include <stdbool.h>

extern bool syscall(size_t code, void* data, size_t data_size);

#endif
