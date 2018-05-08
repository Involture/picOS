#ifndef _WATCHMEN_H
#define _WATCHMEN_H

#include <schtyp.h>
#include <structs/table.h>

// *** GENERAL CONSIDERATIONS ***

/*
  The scheduler is non-preemptive. Meaning a processus has to be sure he
  does not need control before he delegates a task. There is only one thing
  a processus can not theorically forcast : device action.

  The watchmen provide a way to preempt tasks based on device status. A task
  can set an alarm and give back control. The task will be given control back
  when the alarm is triggered.

  Alarms conditions are expressed in the form of boolean formula over watchmen
  status. When the formula becomes true, the alarm is triggered.
 */

// *** TYPE DEFINITIONS ***

/* The following type represents a formula. In the C language, it is simply
   a byte array, and it cant be expressed any more precisely. However,
   a formula can be defined using grammar as following ( ][ is concatenation) :

   formula =   meaning : [operator][formula][formula] 
               bits    :  0      7  8     ?  ?     ?
             | meaning : [base_formula]
               bits    :  0         23

   base_formula = 
              meaning : [1][value][begining][short_operator][address][ mask ]
              bits    :  0    1       2      3            4  5    15  16  23

   operator = meaning : [0][value][begining][not_used][short_operator]
              bits    :  0    1        2     3      5  6            7

   short_operator = [and] | [or] | [not] | [xor]

   and = 00
   or  = 11
   not = 01
   xor = 10

   About the value bits : These bits can be 1 or 0 indifferently when the
   formula is provided for an alarm. It will be later set to the truth value
   of the part of the formula under the binary operator.
   Indeed, when a state_byte changes, all the formula containing its address
   are updated. If some formula are find to become true, the alarm is triggered.

   The beginning bit is set if this is the first byte of the formula. In this
   case, when the value bit is set to 1, the alarm is triggered.
   
   The truth value of base formula is computed as follow :
   Take the state byte at offset 'address' in the wm_state_table.
   Take all the bits of this byte set in the mask.
   Compute : bit1 'short_operator' bit2 'short_operator' bit3 ...
 */

/* This type represent a listener. It is the address of a base_formula.
 */

// *** VARIABLES *** To be moved in kernel code !!!

/* A table of all the state bytes of the watchmen. The fact it is a table 
   allows watchmen to add or remove bytes. The offset in the formulas are
   11 bits long. Consequently, the table has at most 2048 entries.
 */
table_t wm_state_table;

/* This table contains a list of listeners for each state byte and thus has
   also 2048 entries.
 */
table_t wm_listener_list_table;


#endif
