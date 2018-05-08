#include <syscall.h>
#include <stdint.h>

#include <syscalls/task.h>

void task_report(tid_t tid, task_data_t task_data) {
  struct syscall_task_report data;
  data.task = tid;
  data.data = task_data;
  syscall(SYSCALL_TASK_REPORT, data, sizeof(data));
}
