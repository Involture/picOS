#include <stdint.h>

#include <kernel/syscalls/proc.h>
#include <kernel/syscalls/task.h>

bool prio_compare(prio_t prio1, prio_t prio2) {
  int8_t rel_prio1;
  int8_t rel_prio2;
  size_t ind = 0;
  while ( !(((rel_prio1 = va_get(prio1, ind)) == 0) &&
            ((rel_prio2 = va_get(prio2, ind)) == 0)
           )
        ) {
    if (rel_prio1 < rel_prio2)
      return true;
    if (rel_prio1 > rel_prio2)
      return false;
    ind ++;
  }
  return true;
}

bool proc_handle_init() {
  proc_queue = ttpq_create(&prio_compare);
  pdesc ex;
  proc_table = table_create(sizeof(ex));
};

void proc_handle_chprio(pid_t id, prio_t prio) {
  pdesc = table_get(proc_table, id);
  switch (pdesc->state) {
    case PSTATE_VACANT:
      ttpq_enqueue(proc_queue, id, prio);
      break;;
    case default:
      ttpq_update_id(proc_queue, id, prio);
  }
}


pid_t proc_handle_birth(path_t path) {
  proc_t pdesc;           // New process descriptor

  proc_regs_t regs;
  regs.syscall.eip = get_entry_point(path);
  regs.syscall.esp = USER_STACK;

  pdesc.id = table_new(proc_table);
  pdesc.prio = NULL;
  pdesc.buriers = va_create(2, 0);
  pdesc.bury_prio = -1;
  pdesc.code = path;
  pdesc.state = PSTATE_VACANT;
  //pdesc.state_data not initialized here.
  pdesc.regs = regs;
  pdesc.parent = CURRENT_PDESC.id;
  pdesc.children = hashtbl_create(sizeof(proc_t*), 0);
  pedsc.pending = pq_create(sizeof(task_t*));
  pdesc.delegated = pq_create(sizeof(task_t*));

  /* NOTICE THE MEMORY MANAGER THE PROCESS NEEDS TO BE LOADED */
   
  *table_get(proc_table, pdesc.id) = pdesc;
  return pdesc.id;
}

bool proc_handle_bury(pid_t id, proc_regs_t regs) {
  pdesc = CURRENT_PDESC; 
  child_pdesc = table_get(proc_table, id);

  pdesc->state = PSTATE_BURYING;
  pdesc->data.pid = id;
  pdesc->regs = regs;
  child_pdesc->bury_prio = pdesc->prio;
  va_append(child->buriers, &(pdesc->id));

  ttpq_disable_id(proc_queue, id);
  return true
}

bool proc_handle_suicide(pid_t) {

bool proc_handle_kill(pid_t) {
