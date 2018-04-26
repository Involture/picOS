#ifndef _TABLE_H
#define _TABLE_H

#include <stddef.h>
#include <stdbool.h>

/* A general purpose table. Size of the elements can be configured at setup.
   Support the following operations :
   - Create
   - Delete
   - Size
   - Add
   - Remove
   - Set
   - Get
 */

typedef void* table_t;

table_t table_create(size_t, size_t/*, mem_mode_t */);
void table_delete(table_t);
size_t table_size(table_t);
int table_add(table_t, void*);
bool table_remove(table_t, int);
void* table_get(table_t, int);

#endif
