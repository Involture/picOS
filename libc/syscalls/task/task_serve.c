#include <schtyp.h>
#include <task.h>
#include <syscall.h>
#include <syscalls/task.h>

bool task_serve(size_t index) {
  struct data_t td;
  td.ptr = &index;
  td.size = sizeof(index);
  return *((bool*) 
           (syscall(SYSCALL_TASK_SERVE, &td)->ptr)
          );
}
