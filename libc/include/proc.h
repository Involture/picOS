#ifndef _KERNEL_PROC_H
#define _KERNEL_PROC_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <table.h>
#include <prio_queue.h>

// *** TYPE DEFINITIONS ***

typedef unsigned char* path_t;
typedef uint16_t pid_t;

typedef struct {
  code : path_t;
  parent : pid_t;
  children : table_t;
  pending : prio_queue_t;
} proc;

// *** VARIABLES ***

table_t proc_table;   // A table associating pid with their processus.

// *** PARENT SIDE FUNCTIONS ***

/* Create a new process executing the code specified by path
 */ 
pid_t proc_birth(path);

/* Send a signal to a child process, asking it to commit suicide and transfer
   control to the child process.
 */
bool proc_bury(pid_t);

/* Purely instantly kill a child process, without giving it a chance to do
   any action.
 */
void proc_kill(pid_t);

/* Detach the a process and attach it to a new parent */
bool proc_abandon(pid, new_parent_pid);

// *** CHILD SIDE FUNCTIONS ***

/* Terminate the process, free all the memory.
   When calling this function :
   - All the pending delegated tasks are canceled and deleted.
   - All the pending tasks to be served are aborted (reported with cancel code).
   - All the children are killed.
 */
void proc_suicide(void);

#endif
