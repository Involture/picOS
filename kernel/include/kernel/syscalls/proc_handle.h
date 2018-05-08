#ifndef _KERNEL_SYSCALLS_PROC_HANDLE_H
#define _KERNEL_SYSCALLS_PROC_HANDLE_H

#include <stdbool.h>

#include <proc.h>
#include <structs/toogle_tabled_prio_queue.h>

ttpq_t proc_queue;

void proc_handle_init();
void proc_handle_birth(path_t path);
void proc_handle_bury(pid_t);
void proc_handle_kill(pid_t);
void proc_handle_suicide(void);

#endif
