#include <schtyp.h>
#include <task.h>
#include <syscall.h>
#include <syscalls/task.h>

void task_report(tid_t tid, struct data_t task_data) {
  struct syscall_task_report data;
  data.task = tid;
  data.data = task_data;
  struct data_t td;
  td.ptr = &data;
  td.size = sizeof(data);
  syscall(SYSCALL_TASK_REPORT, &td);
}
