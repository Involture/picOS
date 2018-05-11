#include <schtyp.h>
#include <task.h>
#include <syscall.h>
#include <syscalls/task.h>

tid_t task_delegate(pid_t pid, int8_t prio, struct data_t task_data) {
  struct syscall_task_delegate data;
  data.slave = pid;
  data.rel_prio = prio;
  data.data = task_data;
  struct data_t td;
  td.ptr = &data;
  td.size = sizeof(data);
  return *((tid_t*) 
           (syscall(SYSCALL_TASK_DELEGATE, &td)->ptr)
          );
}
