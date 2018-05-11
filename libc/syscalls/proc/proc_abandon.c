#include <stdint.h>
#include <stdbool.h>

#include <schtyp.h>
#include <proc.h>
#include <syscall.h>
#include <syscalls/proc.h>

bool proc_abandon(pid_t pid, pid_t new_parent_pid) {
  struct syscall_proc_abandon data;
  data.child_pid = pid;
  data.new_parent_pid = new_parent_pid;
  struct data_t td;
  td.ptr = &data;
  td.size = sizeof(data);
  return *((bool*) 
           ((syscall(SYSCALL_PROC_ABANDON, &td))->ptr)
          );
}
