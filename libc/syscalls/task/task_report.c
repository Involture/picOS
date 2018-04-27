#include <syscall.h>
#include <stdint.h>

#include <syscalls/task.h>

void task_report(tid_t tid, task_data_t task_data) {
  uint8_t data[sizeof(tid) + sizeof(task_data)];
  *((tid_t*) data) = tid;
  *((task_data_t*) (data + sizeof(tid))) = task_data;
  syscall(SYSCALL_TASK_REPORT, data, sizeof(data));
}
