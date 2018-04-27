#include <syscall.h>

#include <syscalls/proc.h>

void proc_suicide() {
  syscall(SYSCALL_PROC_SUICIDE, NULL, 0);
}
