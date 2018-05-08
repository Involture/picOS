#include <stdint.h>
#include <stdbool.h>
#include <syscall.h>

#include <syscalls/proc.h>

bool proc_abandon(pid_t pid, pid_t new_parent_pid) {
  struct syscall_proc_abandon data;
  data.child_pid = pid;
  data.new_parent_pid = new_parent_pid;
  return *((bool*) syscall(SYSCALL_PROC_ABANDON, *data, sizeof(data));
}
