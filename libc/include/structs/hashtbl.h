#ifndef _HASHTBL_H
#define _HASHTBL_H

#include <stddef.h>

/* A general purpose hash_table. The types of keys and data can be configured
   at setup. The hash function is a general one on bytes.
   Support following operations :
   - Create
   - Delete
   - Add
   - Remove
   - Get
 */

typedef void* hashtbl_t;

hashtbl_t hashtbl_create(size_t, size_t/*, mem_mode_t */);
void hashtbl_delete(hashtbl_t);
void hashtbl_add(hashtbl_t, void*, void*);
void hashtbl_remove(hashtbl_t, void*);
void* hashtbl_get(hashtbl_t, void*);

#endif
