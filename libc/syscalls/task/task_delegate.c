#include <syscalls/task.h>
#include <syscall.h>

#include <stdint.h>

tid_t task_delegate(pid_t pid, int8_t prio, task_data_t task_data) {
  uint8_t data[sizeof(pid) + sizeof(prio) + sizeof(task_data)]; 
  *((pid_t*) data) = pid; 
  *((int8_t*) (data + sizeof(pid))) = prio;
  *((task_data_t*) (data + sizeof(pid) + sizeof(prio))) = task_data;
  return *((tid_t*) syscall(SYSCALL_TASK_DELEGATE, data, sizeof(data)));
}
