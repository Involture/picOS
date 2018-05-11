#include <schtyp.h>
#include <task.h>
#include <syscall.h>
#include <syscalls/task.h>

struct data_t task_claim(tid_t tid) {
  struct data_t td;
  td.ptr = &tid;
  td.size = sizeof(tid);
  return *((struct data_t*) 
           (syscall(SYSCALL_TASK_CLAIM, &td)->ptr)
          );
}
