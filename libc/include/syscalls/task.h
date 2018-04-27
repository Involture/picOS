#ifndef _TASK_H
#define _TASK_H

#include <stdint.h>
#include <stddef.h>
#include <structs/var_array.h>
#include <syscalls/proc.h>

// *** TYPE DEFINITIONS ***

typedef uint16_t tid_t;

/* A priority list is formed with the list of the priorities of the parent 
   tasks. They are compared using lexical order starting with the most ancient
   task. Each element of this list is a signed 8bit integer.
 */
typedef va_t task_prio_t;

/* This is the data type passed in argument for task delegation and report.
 */
typedef struct {
  void* ptr;
  size_t size;
} task_data_t;

typedef enum {
  PENDING,
  SERVED,
  FINISHED,
} task_state_t;

/* A task descriptor
 */
typedef struct {
  tid_t id;
  task_prio_t prio;
  pid_t supervisor_id;
  pid_t slave_id;
  task_data_t data;
  task_state_t state;
  void* position;
  void* report;
} task_t;

// *** SUPERVISOR SIDE FUNCTIONS ***

/* Ask a pid to serve a task. The second argument give the relative priority
   of the task. The priority of the task is computed appendind the relative
   priority to the priority list of the current task.
   The task is enqueued in the task queue of the server process.
   If the integer is positive, control is given back to the current process
   when the task has been reported by the server process (meaning the delegated
   task has a higher priority than the current task.
   If the integer is negative, control is not given to the server process and
   the execution of the current task continues.
   The function also checks the correctness of the data. In case of failure, the
   task is immediatly aborted.
 */
tid_t task_delegate(pid_t, int8_t, task_data_t);

/* Claim the result of a given delegated task.
   Two cases can occure :
   - The task is finished : the current task keeps control and the data of
   the report is instantly returned.
   - The task is being served or is pending : Control is transfered to the
   server process until the task is finished.
 */
task_data_t task_claim(tid_t);

// *** SLAVE SIDE FUNCTIONS ***

/* n being the argument, return a pointer to the n_th most prioritized
   task in the pending queue. Return a null pointer if there is less that n
   tasks pending.
 */
task_t* task_read(size_t);

/* n being the argument, label the n_th task in the pending stack as being
   served.
   The new priority of the process is set to be the maximum of all the tasks 
   currently served.
   Return false if there is less than n tasks or if the n_th task is already
   being served.
 */
bool task_serve(size_t);

/* Send a report for a finished task. The task is available for a claim.
   If other tasks are being served, priority is set to be the new maximum of
   the tasks being served. Give back control if an other stack with a higher
   priority can be executed.
 */
void task_report(tid_t, task_data_t);

// *** COMMENTS ON MEMORY ACCESS CONSIDERATIONS ***
/* Plz refere to proc.h.
 */

#endif
