#include <syscall.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include <syscalls/watchmen.h>

bool wm_alarm(wm_formula_t formula, size_t formula_size) {
  uint8_t data[sizeof(formula) + sizeof(formula_size)];
  *((wm_formula_t*) data) = formula;
  *((size_t*) (data + sizeof(formula))) = formula_size;
  return *((bool*) syscall(SYSCALL_WATCHMEN_ALARM, data, sizeof(data)));
}
