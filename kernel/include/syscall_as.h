#ifndef _SYSCALL_AS_H
#define _SYSCALL_AS_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* Function called to make a syscall
 */
extern void* syscall(size_t, void*, size_t);

/* Enable syscalls. 
 */
extern void syscall_enable(void);

/* Set the kernel stack
 */
extern void syscall_set_stack(uint32_t);

#endif
