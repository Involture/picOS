#ifndef _SYSCALL_H
#define _SYSCALL_H

#include <stddef.h>
#include <stdint.h>
#include <proc.h>
#include <task.h>
#include <watchmen.h>

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

// Now we define the structurs used to pass arguments to the kernel :

struct syscall_proc_abandon {
  pid_t child_pid;
  pid_t new_parent_pid;
};
struct syscall_task_delegate {
  pid_t slave;
  int8_t rel_prio;
  task_data_t data;
};
struct syscall_task_report {
  tid_t task;
  task_data_t data;
};
struct syscall_wm_alarm {
  wm_formula_t formula;
  size_t size;
};

/* A fonction to make a syscall. Calling sysenter directly will eventually cause
   and exception.
   - Returns a pointer to data returned by the kernel.
   - First argument is the call code
   - Second argument is a pointer to the data transmitted to the kernel.
   - Third argument is the size of this data.
 */

extern task_data_t* syscall(uint16_t, void*, size_t);

#endif
