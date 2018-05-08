#ifndef _PRIO_H
#define _PRIO_H

#include <structs/var_array.h>

/* A priority list is formed with the list of the priorities of the parent 
   tasks. They are compared using lexical order starting with the most ancient
   task. Each element of this list is a signed 8bit integer.
 */
typedef va_t prio_t;
typedef uint16_t tid_t;
typedef uint16_t pid_t;
typedef uint8_t* wm_formula_t;
typedef uint8_t* wm_listener_t;

bool prio_compare(prio_t, prio_t);

#endif
