#include <stdint.h>
#include <stdbool.h>
#include <syscall.h>

#include <syscalls/proc.h>

bool proc_abandon(pid_t pid, pid_t new_parent_pid) {
  pid_t data[2];
  data[0] = pid;
  data[1] = new_parent_pid;
  return *((bool*) syscall(SYSCALL_PROC_ABANDON, data, 4));
}
