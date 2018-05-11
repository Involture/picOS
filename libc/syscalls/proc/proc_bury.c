#include <stdbool.h>

#include <schtyp.h>
#include <proc.h>
#include <syscall.h>
#include <syscalls/proc.h>

bool proc_bury(pid_t pid) {
  struct data_t td;
  td.ptr = &pid;
  td.size = sizeof(pid);
  return *((bool*) 
           (syscall(SYSCALL_PROC_BURY, &td)->ptr)
          );
}
