#include <stdint.h>
#include <stdbool.h>

#include <kernel/cpuid.h>

// Assembly functions
extern uint32_t get_cpuid(uint32_t*);
//

uint32_t cpuid_value = 0;
uint32_t* cpuid = &cpuid_value;

void cpuid_set(void) {
  get_cpuid(cpuid);
}
bool cpuid_has_feat(uint32_t feat) {
  return (bool) (*cpuid & feat);
}
