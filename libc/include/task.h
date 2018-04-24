#ifndef _KERNEL_TASK_H
#define _KERNEL_TASK_H

#include <stdint.h>
#include <stddef.h>
#include <proc.h>

// *** TYPE DEFINITIONS ***

typedef uint16_t tid_t;
/* A priority list is formed with the list of the priorities of the parent 
   tasks. They are compared using lexical order starting with the most ancient
   task. Each element of this list is a signed 8bit integer.
   This list is stored in an array of variable size.
 */
typedef var_array prio_t;

/* This is the data type passed in argument for task delegation and report.
   The first field is a pointer to the data. When paging will be enable, it
   will be necessary that this pointer describe a location in a special page,
   shared between a processus, its supervisors and its slaves.
   The data pointer will be obtained through a call to a special function form
   malloc family.
   When function use a data_t argument, they must check that the data pointer
   is valid.
   In the case the data is the argument of a report. A null pointer means the
   task has been aborted. In this case, size is undefined.
 */
typedef struct {
  ptr : void*;
  size : size_t;
} data_t

typedef struct {
  id : tid_t;
  prio : prio_t;
  supervisor_id : pid_t;
  slave_id : pid_t;
  data : data_t;
} task_t

typedef enum {
  PENDING,    // Task is pending, the slave process is already occupied. In
              //   this case the address of the task in its priority queue is
              //   available in the state_data field.
  SERVED,     // Task is being served by the slave process. In this case the
              //  state_data field is undefined.
  FINISHED,   // The slave has finished processing the task and report is
              //   available. The state_data field contain the address of
              //   the reported data.
} state_lable_t

typedef struct {
  state_label : state_label_t;
  state_data : void*;             // Undefined if state_label != PENDING
};

// A task associated with its state.
typedef struct {
  task : task_t;
  state : state_t;
} stask_t

typedef bool suicide_handler_t(void);
typedef bool cancel_handler_t(tid_t);

// *** VARIABLES ***

table_t stask_table;   // A table associating tid with some stasks.

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
tid_t delegate(pid_t, int8_t, data_t);

/* Claim the result of a given delegated task.
   Three cases can occure :
   - The task is finished : the current task keeps control and the data of
   the report is instantly returned.
   - The task is being served or is pending : Control is transfered to the
   server process until the task is finished.
   - The task has been canceled : a data is returned with data pointer equal
   to 0xFFFFFFFFFFFFFFFF.
 */
data claim(tid_t);

/* Change the priority of a delegated task. A new priority list is computed
   using the relative priority given in argument.
   Three cases can occure :
   - The task is pending : The priority of the task is simply changed in the
   priority queue. The function returns true.
   - The task is being served : Control is transfered to the
   server process and its prio handler is called. If no handler has been 
   defined or if the handler returns false. Chg_prio returns false. Errno is 
   set accordingly.
   - The task is finished : Nothing happends. The function returns false and
   errno is set accordingly.
 */
bool chg_prio(tid_t, int8_t);

/* Cancel a task. Two cases can occure :
   - The task is pending : The task is removed from the queue of the server
   process. It is labeled as finish with a reported data pointer equal to
   0xFFFFFFFFFFFFFFFF.
   - The task is being served : Control is transfered to the server pid and
   its cancel handler called. If no handler has been defined or if the handler 
   returns false, the function return false and errno is set accordingly.
   - The task is finished : The data pointer of the report is set to
     0xFFFFFFFFFFFFFFFF.
 */
bool cancel(tid_t);

/* Delete a delegated task. Loose any interest in it. In practice, the task
   is first canceled (see above). Then the task is registered to be claimed
   by the kernel as soon as a report for it has been produced. 
 */
void delete(tid_t);

// *** SLAVE SIDE FUNCTIONS ***
/* The current task is returned. As the process has control, it has a task to
   complete.
 */
task_t get_task(void);

/* Start serving a new task without reporting the current one. The priority of
   the process is set to be the maximum of all the tasks currently served.
   If other task is pending, the function return false and nothing happens.
   After a call to next_task, the get_task function will return the newly served
   task. Consequently, previous tasks have to be saved by the slave.
 */
bool next_task(void);

/* Send a report for a finished task. The task is available for a claim.
   If other tasks are being served, priority is set to be the new maximum of
   the tasks being served. In any case, control is given back.
 */
void report (tid_t, data_t);

/* Cancel a task being served. Equivalent to a report with a data pointer equal
   to 0xFFFFFFFFFFFFFFFF.
 */
void abort (tid_t);

/* Set a handler for a specific signal. Return true if the handler has been
 succefully set. When the handler returns, the control is always given back to
 the sender of the signal.
 */
bool handle_suicide(suicide_handler_t);
bool handle_cancel(cancel_handler_t);
