#include <stdint.h>

#include <kernel/syscalls/proc.h>
#include <kernel/syscalls/task.h>
#include <kernel/switch>

#define USER_STACK (1 << 22)

static int new_pid = 0;
static int new_dir = 5;
struct proc_t proc_table[128];
static uint32_t USER_STACK = 0x800000;

/*
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
*/

/*
bool proc_handle_init() {
  proc_queue = ttpq_create(&prio_compare);
  pdesc ex;
  proc_table = table_create(sizeof(ex));
};
*/

/*
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
*/

pid_t proc_handle_birth(path_t path) {
  struct proc_t pdesc; // New process descriptor

  union proc_regs_t regs;
  regs.syscall.eip = get_entry_point(path);
  regs.syscall.esp = USER_STACK;

  pdesc.id = new_pid;
  new_pid++;
  if (new_pid == 128) puts("Max process number reached")
  pdesc.prio = NULL;
  pdesc.code = path;
  pdesc.state = PSTATE_VACANT;
  //pdesc.state_data not initialized here.
  pdesc.regs = regs;
  //pdesc.parent = ; #TODO Write syscall to get current pid
  //pdesc.pending = pq_create(sizeof(task_t*)); NOT IMPLEMENTED
  pdesc.dir_code  = new_dir;
  new_dir++;
  pdesc.dir_stack = new_dir;
  new_dir++;
  pdesc.dir_code  = new_dir;
  new_dir++;

  /* NOTICE THE MEMORY MANAGER THE PROCESS NEEDS TO BE LOADED */
  proc_table[pdesc.id] = pdesc;
  return pdesc.id;
}

/*
bool proc_handle_bury(pid_t id, proc_regs_t regs) {
  struct proc_t pdesc = proc_table[switch_curr_proc]; 
  child_pdesc = table_get(proc_table, id);

  pdesc->state = PSTATE_BURYING;
  pdesc->data.pid = id;
  pdesc->regs = regs;
  child_pdesc->bury_prio = pdesc->prio;
  va_append(child->buriers, &(pdesc->id));

  ttpq_disable_id(proc_queue, id);
  return true
}
*/

// bool proc_handle_suicide(pid_t) {

// bool proc_handle_kill(pid_t) {
