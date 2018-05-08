#ifndef _STRUCTS_TOOGLE_TABLED_PRIO_QUEUE_H
#define _STRUCTS_TOOGLE_TABLED_PRIO_QUEUE_H

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
   Elements in this priority queue are tooglable. Meaning they can be excuded
   for futur operations for a moment.

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
   - Enable_id
   - Disable_id
   Delete_top and Read_top are equivalent to Delete(0) and Read(0).
 */

typedef void* ttpq_t;
typedef uint32_t ttpq_id_t;

/* The type of a comparison function. Return true if first argument is inferior
   or equal to the second
 */
typedef bool (*ttpq_compare_t)(void*, void*);

ttpq_t ttpq_create(ttpq_compare_t);
void ttpq_delete(ttpq_t);

bool ttpq_is_empty(ttpq_t);

/* The second argument is the identifier, the third argument is the element, 
   the fourth is the priority.
 */
bool ttpq_add(ttpq_t, ttpq_id_t, void*, void*);

void ttpq_remove_top(ttpq_t);
void* ttpq_read_top(ttpq_t);
void ttpq_remove(ttpq_t, size_t);
void* ttpq_read(ttpq_t, size_t);

void ttpq_remove_id(ttpq_t, ttpq_id_t);
void* ttpq_read_id(ttpq_t, ttpq_id_t);
void ttpq_update_id(ttpq_t, ttpq_id_t, void*);

void ttpq_enable_id(ttpq_t, ttpq_id_t);
void ttpq_disable_id(ttpq_t, ttpq_id_t);

#endif
