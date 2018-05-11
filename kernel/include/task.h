#ifndef _TASK_H
#define _TASK_H

#include <stdint.h>
#include <stddef.h>

/* This is the data type passed in argument for task delegation and report.
 */
enum task_state_t {
  TSTATE_PENDING,
  TSTATE_SERVED,
  TSTATE_FINISHED,
};

/* A task descriptor
 */
struct tdesc_t {
  tid_t id;
  prio_t prio;
  pid_t supervisor_id;
  pid_t slave_id;
  struct data_t data;
  enum task_state_t state;
  struct data_t report;
};

#endif
