#include <syscall.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include <syscalls/watchmen.h>

bool wm_alarm(wm_formula_t formula, size_t formula_size) {
  struct syscall_wm_alarm data;
  data.formula = formula;
  data.size = formula_size;
  return *((bool*) syscall(SYSCALL_WATCHMEN_ALARM, data, sizeof(data)));
}
