#ifndef _TABLE_H
#define _TABLE_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* A general purpose fixed size table. Size of the elements can be configured at    setup.
   Support the following operations :
   - Create
   - Delete
   - Size
   - Add
   - Remove
   - Get
 */

typedef void* table_t;

void table_create(size_t, size_t);
void table_delete(table_t);
size_t table_size(table_t);
uint32_t table_new(table_t);
bool table_remove(table_t, uint32_t);
void* table_get(table_t, uint32_t);

#endif
