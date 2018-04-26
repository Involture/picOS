#ifndef _VAR_ARRAY_H
#define _VAR_ARRAY_H

#include <stddef.h>

/* A general purpose resizable array. Element type can be set at setup.
   Following operations are supported :
   - Create
   - Delete
   - Get
 */

typedef void* va_t;

va_t va_create(size_t, size_t/*, mem_mode_t */);
void va_delete(va_t);
void* va_get(va_t, size_t);

#endif
