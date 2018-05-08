#ifndef _TASK_H
#define _TASK_H

#include <stdint.h>
#include <stddef.h>
#include <schtyp.h>

/* This is the data type passed in argument for task delegation and report.
 */
typedef struct foo {
  void* ptr;
  size_t size;
} __attribute__((__packed__))
task_data_t;

typedef enum {
  TSTATE_PENDING,
  TSTATE_SERVED,
  TSTATE_FINISHED,
} task_state_t;

/* A task descriptor
 */
typedef struct {
  tid_t id;
  prio_t prio;
  pid_t supervisor_id;
  pid_t slave_id;
  task_data_t data;
  task_state_t state;
  task_data_t report;
} tdesc_t;

#endif
