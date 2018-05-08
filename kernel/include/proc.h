#ifndef _PROC_H
#define _PROC_H

#include <stdint.h>
#include <schtyp.h>
#include <structs/prio_queue.h>
#include <structs/table.h>

/*** TEMPORARY, waiting for the header of the file system */
typedef unsigned char* path_t;
/***/

typedef struct {
  uint32_t eip;
  uint32_t edi;
  uint32_t esi;
  uint32_t ebp;
  uint32_t esp;
  uint32_t edx;
  uint32_t ecx;
  uint32_t ebx;
  uint32_t eax;
} proc_preempted_state_t;

typedef struct {
  uint32_t eip;
  uint32_t esp;
} proc_syscall_state_t;

typedef enum {
  PSTATE_VACANT,
  PSTATE_RUNNABLE_SYSCALL,
  PSTATE_RUNNABLE_PREEMPTED,
  PSTATE_BURYING,
  PSTATE_CLAIMING,
  PSTATE_SLEEPING,
} proc_state_t;

typedef union {
  pid_t pid;
  tid_t tid;
  wm_formula_t formula;
} proc_state_data_t;

typedef union {
  proc_preempted_state_t preempted;
  proc_syscall_state_t syscall;
} proc_regs_t;

typedef struct {
  pid_t id;
  prio_t prio;
  path_t code;
  proc_state_t state;
  proc_state_data_t state_data;
  proc_regs_t regs;
  pid_t parent;
  pq_t pending;
} proc_t;

table_t proc_table;

#endif
