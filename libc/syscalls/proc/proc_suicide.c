#include <schtyp.h>
#include <proc.h>
#include <syscall.h>
#include <syscalls/proc.h>

void proc_suicide() {
  struct data_t td;
  td.ptr = NULL;
  td.size = 0;
  syscall(SYSCALL_PROC_SUICIDE, &td);
}
