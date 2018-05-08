#ifndef _TABLED_PRIO_QUEUE_H
#define _TABLED_PRIO_QUEUE_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* This is a general purpose priority queue. It stores POINTERS and only this.
   Thus, if you wish to organise data using this structure, you MUST allocate
   the data somewhere else.
   This priority queue is tabled, meaning than when adding an argument, you must
   provide a UNIQUE identifier for it. The position of the data in the structure
   is stored in a separated table. This allow deleting or updating elements in
   the data structure.
   Identifier are stored in a table. They are thus meant to be quit contiguous
   integers. The table data structure provides a mechanisme to acquire such
   identifier.

   It supports following operations :
   - Create
   - Delete
   - Is_empty
   - Add
   - Remove_top
   - Read_top
   - Remove(n)
   - Read(n)
   - Remove_id
   - Update_id
   - Read_id
   Delete_top and Read_top are equivalent to Delete(0) and Read(0).
 */

typedef void* tpq_t;
typedef uint32_t tpq_id_t;

/* The type of a comparison function. Return true if first argument is inferior
   or equal to the second
 */
typedef bool (*tpq_compare_t)(void*, void*);

tpq_t tpq_create(tpq_compare_t);
void tpq_delete(tpq_t);

bool tpq_is_empty(tpq_t);

/* The second argument is the identifier, the third argument is the element, 
   the fourth is the priority.
 */
bool tpq_add(tpq_t, tpq_id_t, void*, void*);

void tpq_remove_top(tpq_t);
void* tpq_read_top(tpq_t);
void tpq_remove(tpq_t, size_t);
void* tpq_read(tpq_t, size_t);

void tpq_remove_id(tpq_t, tpq_id_t);
void* tpq_read_id(tpq_t, tpq_id_t);
void tpq_update_id(tpq_t, tpq_id_t, void*);

#endif
