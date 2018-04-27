#include <syscall.h>

#include <syscalls/proc.h>

pid_t proc_birth(path_t path) {
  return *((pid_t*) syscall(SYSCALL_PROC_BIRTH, &path, 1));
}
