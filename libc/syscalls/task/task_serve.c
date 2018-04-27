#include <syscall.h>
#include <stdbool.h>
#include <stddef.h>

#include <syscalls/task.h>

bool task_serve(size_t index) {
  return *((bool*) syscall(SYSCALL_TASK_SERVE, &index, sizeof(index)));
}
