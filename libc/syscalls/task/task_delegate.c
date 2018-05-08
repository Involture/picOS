#include <syscalls/task.h>
#include <syscall.h>

#include <stdint.h>

tid_t task_delegate(pid_t pid, int8_t prio, task_data_t task_data) {
  struct syscall_task_delegate data;
  data.slave = pid;
  data.rel_prio = prio;
  data.data = task_data;
  return *((tid_t*) syscall(SYSCALL_TASK_DELEGATE, data, sizeof(data)));
}
