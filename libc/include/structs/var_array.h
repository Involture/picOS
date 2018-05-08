#ifndef _STRUCTS_VAR_ARRAY_H
#define _STRUCTS_VAR_ARRAY_H

#include <stddef.h>

/* A general purpose resizable array. Element type can be set at setup.
   Following operations are supported :
   - Create
   - Delete
   - Get
   - Get length
   - Append to end
   - Copy
 */

typedef void* va_t;

va_t va_create(size_t, size_t);
va_t va_copy(va_t);
void va_delete(va_t);
void* va_get(va_t, size_t);
size_t va_len(va_t);
void va_append(va_t, void*);


#endif
