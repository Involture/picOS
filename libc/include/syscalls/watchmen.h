#ifndef _WATCHMEN_H
#define _WATCHMEN_H

#include <stdint.h>
#include <structs/table.h>
#include <structs/var_array.h>

/* Read a state byte. Only the first 11 bytes of the argument are used.
 */
uint8_t wm_read(uint16_t);

/* Set an alarm ! The correctness of the formula must be checked when by this
   function. Return false if the formula was not correct. Otherwise, take
   control and return true when control is given back.
 */
bool wm_alarm(wm_formula_t, size_t);

#endif
