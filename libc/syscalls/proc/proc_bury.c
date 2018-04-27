#include <stdbool.h>
#include <syscall.h>

#include <syscalls/proc.h>

bool proc_bury(pid_t pid) {
  return *((bool*) syscall(SYSCALL_PROC_BURY, &pid, 2));
}
