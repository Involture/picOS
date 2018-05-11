#include <schtyp.h>
#include <task.h>
#include <syscall.h>
#include <syscalls/task.h>

struct tdesc_t* task_read(size_t index) {
  struct data_t td;
  td.ptr = &index;
  td.size = sizeof(index);
  return ((struct tdesc_t*)
          (syscall(SYSCALL_TASK_READ, &td)->ptr)
         );
}
