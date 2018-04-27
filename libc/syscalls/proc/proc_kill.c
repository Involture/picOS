#include <stdbool.h>
#include <syscall.h>

#include <syscalls/proc.h>

bool proc_kill(pid_t pid) {
  return *((bool*) syscall(SYSCALL_PROC_KILL, &pid, 2));
}
