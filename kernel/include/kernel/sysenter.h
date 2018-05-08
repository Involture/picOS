#ifndef _KERNEL_SYSENTER_H
#define _KERNEL_SYSENTER_H

#include <stdint.h>
#include <task.h>

extern void sysenter_init(void);
extern void sysexit(void)
__attribute__((__noreturn__));
extern bool sysreturn(uint32_t, uint32_t, task_data_t*);

/* The system call entry point.
   - Return a pointer to data transmitted to the calling process. Can be a NULL
   pointer if no data is to be returned.

   - First argument is the call code (see include/syscall.h).
   - Second argument is the caller stack pointer.
   - Third argument is the caller return instruction pointer.
   - Fourth argument is a pointer to the data transmitted by the caller.
   - Fifth argument is the size of the data transmitted by the caller.
   processus, can be NULL.
 */

__attribute__((__noreturn__))
void sysenter_master_handler(uint16_t, uint32_t, uint32_t, 
                             void*, size_t);

#endif
