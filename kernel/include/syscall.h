#ifndef _SYSCALL_H
#define _SYSCALL_H

#include <stddef.h>
#include <syscall_as.h>

#define SYSCALL_PROC_BIRTH      0x0000
#define SYSCALL_PROC_BURY       0x0001
#define SYSCALL_PROC_KILL       0x0002
#define SYSCALL_PROC_ABANDON    0x0003
#define SYSCALL_PROC_SUICIDE    0x0010
#define SYSCALL_TASK_DELEGATE   0x0100
#define SYSCALL_TASK_CLAIM      0x0101
#define SYSCALL_TASK_READ       0x0110
#define SYSCALL_TASK_SERVE      0x0111
#define SYSCALL_TASK_REPORT     0x0112
#define SYSCALL_WATCHMEN_READ   0x0200
#define SYSCALL_WATCHMEN_ALARM  0x0201

/* The function called in ring 0 to handle syscalls
 */
void syscall_master_handler(size_t, void*, size_t);
void* syscall(size_t, void*, size_t);

#endif
