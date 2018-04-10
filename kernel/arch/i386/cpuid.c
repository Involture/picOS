#include <kernel/cpuid.h>
#include <stdio.h>

uint32_t cpuid_value = 0;
uint32_t* cpuid = &cpuid_value;
void cpuid_set(void) {
  get_cpuid(cpuid);
}
bool cpuid_has_feat(int feat) {
  return (bool) (*cpuid & feat);
}
