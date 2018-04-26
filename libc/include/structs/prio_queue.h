#ifndef _PRIO_QUEUE_H
#define _PRIO_QUEUE_H

#include <stddef.h>
#include <stdbool.h>

/* This is a general purpose priority queue. A queue can be created to contain
   elements of a choosed size.
   It supports following operations :
   - Create
   - Delete
   - Is_empty
   - Add
   - Remove_top
   - Read_top
   - Remove(n)
   - Read(n)
   Delete_top and Read_top are equivalent to Delete(0) and Read(0).
   The structure should be implemented assuming than Delete_top and Read_top
   will be called much more often than Delete(n) and Read(n).
 */

typedef void* pq_t;

/* The type of a comparison function. Return true if first argument is inferior
   or equal to the second
 */
typedef bool pq_compare_t(void*, void*);

/* The first argument is a function to compare the keys passed as priorities.
   The second argument is the size in byte of the element the queue is going to
   contain.
   The third element is the memory mode, i.e., in which memory area
   (regarding permissions) the queue should be created.
 */
pq_t pq_create(pq_compare_t, size_t/*, mem_mode_t */);
void pq_delete(pq_t);

bool pq_is_empty(pq_t);

/* The second argument is the element, the third is the priority.
 */
bool pq_add(pq_t, void*, void*);

void pq_remove_top(pq_t);
void* pq_read_top(pq_t);
void pq_remove(pq_t, size_t);
void* pq_read(pq_t, size_t);

#endif
