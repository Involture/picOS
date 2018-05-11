#include <schtyp.h>
#include <watchmen.h>
#include <syscall.h>
#include <syscalls/watchmen.h>

bool wm_alarm(wm_formula_t formula, size_t formula_size) {
  struct syscall_wm_alarm data;
  data.formula = formula;
  data.size = formula_size;
  struct data_t td;
  td.ptr = &data;
  td.size = sizeof(data);
  return *((bool*) 
           (syscall(SYSCALL_WATCHMEN_ALARM, &td)->ptr)
          );
}
