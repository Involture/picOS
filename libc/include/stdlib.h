#ifndef _STDLIB_H
#define _STDLIB_H

#include <sys/cdefs.h>
#include <stdio.h>

#ifdef __MY_DEBUG__
  #define assert(expression) \
    ( (expression) ? (void) 0 : \
      (puts("Assertion failed, in fonction " __func__ \
           ", in file " __FILE__ ", line " __LINE__ " : " \
           "expression"), panic()) \
    )
#else
  #define assert(ignore) ((void) 0)
#endif

__attribute__((__noreturn__))
void panic(void);

#endif
