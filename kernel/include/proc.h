#ifndef _PROC_H
#define _PROC_H

#include <stdint.h>
#include <structs/prio_queue.h>
#include <structs/table.h>

/*** TEMPORARY, waiting for the header of the file system */
typedef unsigned char* path_t;
/***/

struct proc_preempted_state_t {
  uint32_t eip;
  uint32_t edi;
  uint32_t esi;
  uint32_t ebp;
  uint32_t esp;
  uint32_t edx;
  uint32_t ecx;
  uint32_t ebx;
  uint32_t eax;
};

struct proc_syscall_state_t {
  uint32_t eip;
  uint32_t esp;
};

enum proc_state_t {
  PSTATE_VACANT,
  PSTATE_RUNNABLE_SYSCALL,
  PSTATE_RUNNABLE_PREEMPTED,
  PSTATE_BURYING,
  PSTATE_CLAIMING,
  PSTATE_SLEEPING,
};

union proc_state_data_t {
  pid_t pid;
  tid_t tid;
  wm_formula_t formula;
};

union proc_regs_t {
  struct proc_preempted_state_t preempted;
  struct proc_syscall_state_t syscall;
};

struct proc_t {
  pid_t id;
  prio_t prio;
  path_t code;
  enum proc_state_t state;
  union proc_state_data_t state_data;
  union proc_regs_t regs;
  pid_t parent;
  pq_t pending;
};

table_t proc_table;

#endif
