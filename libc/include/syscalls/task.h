#ifndef _SYSCALLS_TASK_H
#define _SYSCALLS_TASK_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

// *** TYPE DEFINITIONS ***

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
tid_t task_delegate(pid_t, int8_t, struct data_t);

/* Claim the result of a given delegated task.
   Two cases can occure :
   - The task is finished : the current task keeps control and the data of
   the report is instantly returned.
   - The task is being served or is pending : Control is transfered to the
   server process until the task is finished.
 */
struct data_t task_claim(tid_t);

// *** SLAVE SIDE FUNCTIONS ***

/* n being the argument, return a pointer to the n_th most prioritized
   task in the pending queue. Return a null pointer if there is less that n
   tasks pending.
 */
struct tdesc_t* task_read(size_t);

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
void task_report(tid_t, struct data_t);

// *** COMMENTS ON MEMORY ACCESS CONSIDERATIONS ***
/* Plz refere to proc.h.
 */

#endif
