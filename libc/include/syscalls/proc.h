#ifndef _SYSCALLS_PROC_H
#define _SYSCALLS_PROC_H

#include <stdbool.h>

// *** PARENT SIDE FUNCTIONS ***

/* Create a new process executing the code specified by path
 */ 
pid_t proc_birth(path_t);

/* Wait for the processus to commit suicide. The processus calling this
   function is simply put in a waiting state. Control is transfered to the
   highest priority waiting process. Once the child commited suicide, the
   process becomes available for running again.
 */
bool proc_bury(pid_t);

/* Purely instantly kill a child process, without giving it a chance to do
   any action.
   The action performed are the same as if the child process had called
   proc_suicide (see below).
 */
bool proc_kill(pid_t);

/* Detach the a process and attach it to a new parent */
bool proc_abandon(pid_t, pid_t);

// *** CHILD SIDE FUNCTIONS ***

/* Terminate the process, free all the memory.
   When calling this function :
   - All the pending delegated tasks are labeled to be claimed by the kernel.
   - All the pending tasks to be served reported with an null pointer as data.
   - All the children are killed.
 */
void proc_suicide(void);

// *** COMMENTS ON MEMORY ACCESS CONSIDERATIONS ***

/* The memory manager must consider which data is accessible to which process.
   Hardware memory protection must be implemented to ensure security.

   Here we examinate the data declared in this files and in task.h. We list,
   for all of them, the permissions that should be set. We use the following
   notations :

   To name a processus :
     * K is the kernel.
   For a process descriptor :
     * I is the processus itself
     * A are all the ancestors of the concerned process
   For a task descriptor :
     * M is the supervisor
     * S is the salve
     * MA are the ancestors of the supervisor
     * SA are the ancestors of the slave

   To name a permission :
     * R is reading permission
     * W is writing permission

   To each datum, we associate a list of permissions of the form
   processus:permission.
   Any omitted processus has no permission.

   Process descriptor : K:RW, I :R , A :R
   ( See watchmen.h to know what a formula is )
   Formula            : K:RW, I :RW, A :R
   ( See task.h to know what these objects are )
   Task descriptor :    K:RW, M :R , S :R , MA:R , SA:R
   Task prio :          K:RW, M :R , S :R , MA:R , SA:R
   Task data :          K:RW, M :RW, S :R , MA:R , SA:R
   Task report :        K:RW, M :R , S :RW, MA:R , SA:R

   The goal of the memory manager is :
   - To create a resizeable physical memory area for each datum.
   - To map the each area to any process that has read access on it.
   - To ensure the area is not mapped for any process that hasnt memory access
   on it.
   - To set permissions for processes that has write access.
   - To minimize the changements of memory mapping when context switching. In
   order to do this, multiple processus that have a read access on the same
   datum should, has much as possible, have this datum mapped to the same
   virtual address.

   GOOD LUCK PADAWAN, MAY THE FORCE BE WITH YOU.
 */

#endif
