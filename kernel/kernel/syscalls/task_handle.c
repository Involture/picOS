#include <kernel/sysenter.h>

#include <kernel/syscalls/task_handle.h>

void task_handle_init() {
  task_table = table_create(100);
}

void task_handle_delegate(pid_t slave_id, int8_t rel_prio, 
                          data_t data, proc_regs_t regs) {
  pdesc = CURRENT_PDESC;
  slave_pdesc = table_get(proc_table, slave_id);

  prio_t prio = pdesc->prio;
  va_append(new_prio, rel_prio);

  tdesc_t tdesc;
  tdesc.id = table_new(task_table);
  tdesc.prio = prio;
  tdesc.supervisor_id = pdesc.id;
  tdesc.slave_id = slave_id;
  tdesc.data = data;
  tdesc.state = TSTATE_PENDING;
  tdesc.report = NULL;

  *table_get(task_table, tdesc.id) = tdesc; 
  pq_enqueue(slave_pdesc->pending, tdesc.id);

  slave_prio = prio_max(slave_pdesc->prio, tdesc_prio);
  proc_handle_chprio(slave_id, slave_prio);
}

struct data_t task_handle_claim(tid_t id) {
  pdesc = CURRENT_DESC; 
  tdesc = table_get(task_table, id);
  struct data_t empty;
  empty.size = 0;
  empty.prt = NULL;
  switch (tdesc->state) {
    case TSTATE_FINISHED:
      report = tdesc.report;
      table_remove(task_table, id);
      return report;
      break;;
    case default:
      pdesc.state = PSTATE_CLAIMING;
      pdesc.state_data.task = id;
      return empty;
} 

bool task_handle_serve(size_t index) {
  pdesc = CURRENT_DESC;
  tid = pq_read(pdesc->pending, index);
  tdesc = table_get(task_table, tid);
  switch (tdesc->state) {
    case TSTATE_PENDING:
      tdesc->state = TSTATE_SERVED;
      return true;
      break;;
    case default :
      return false;
  }
}

bool task_handle_report(tid_t id, struct data_t data) {
  tdesc = table_get(task_table, id);
  supervisor_desc = table_get(proc_table, tdesc->supervisor);
  switch (tdesc->state) {
    case TSTATE_SERVED:
      tdesc->report = data;
      tdesc->state = TSTATE_FINISHED;
      pq_remove(tdesc->pending, id);
      switch (supervisor_desc->state) {
        case PSTATE_CLAIMING 


