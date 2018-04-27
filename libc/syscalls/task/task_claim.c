#include <syscall.h>

#include <syscalls/task.h>

task_data_t task_claim(tid_t tid) {
  return *((task_data_t*) syscall(SYSCALL_TASK_CLAIM, &tid, sizeof(tid)));
}
