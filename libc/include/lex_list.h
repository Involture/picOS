#ifndef _LEX_LIST_H
#define _LEX_LIST_H

/* A general purpose linked list, with an additionnal comparison operation.
   Size of elements can be configurate at creation. Support the following
   operations :
   - Create
   - Is empty
   - Add
   - Get
   - Compare
 */

typedef /* To be completed */ ll_t;
typedef bool ll_compare_t(void*, void*);

typedef struct {
  head : void*,
  tail : ll_t,
} ll_get_t;

ll_t ll_create_t(size_t, /* TO BE COMPLETED BY THE MEMORY HEADER TYPES */);

bool ll_is_empty(ll_t);
ll_t ll_add(ll_t, void*);
ll_get_t ll_get(ll_t);

/* Lexical compare starting with the elements at the tail of the list, using
   the function provided.
 */
bool ll_compare(ll_compare_t, ll_t, ll_t);

#endif
