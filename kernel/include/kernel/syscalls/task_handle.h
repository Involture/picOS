#ifndef _KERNEL_SYSCALLS_TASK_HANDLE_H
#define _KERNEL_SYSCALLS_TASK_HANDLE_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <task.h>
#include <proc.h>

table_t task_table;

void task_handle_init(void);
void task_handle_delegate(pid_t, int8_t, task_data_t);
void task_handle_claim(tid_t);
void task_handle_serve(size_t);
void task_handle_report(tid_t, task_data_t);

#endif
