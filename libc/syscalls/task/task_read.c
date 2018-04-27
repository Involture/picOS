#include <syscall.h>
#include <stddef.h>

#include <syscalls/task.h>

task_t* task_read(size_t index) {
  return ((task_t*) syscall(SYSCALL_TASK_READ, &index, sizeof(index)));
}
