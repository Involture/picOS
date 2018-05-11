#include <string.h>

#include <schtyp.h>
#include <proc.h>
#include <syscall.h>
#include <syscalls/proc.h>

pid_t proc_birth(path_t path) {
  struct data_t td;
  td.ptr = path;
  td.size = strlen(path);
  return *((pid_t*) 
           (syscall(SYSCALL_PROC_BIRTH, &td)->ptr)
          );
}
