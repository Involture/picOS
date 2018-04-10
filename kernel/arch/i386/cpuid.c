#include <kernel/cpuid.h>
#include <stdio.h>

uint32_t cpuid_value = 0;
uint32_t* cpuid = &cpuid_value;
void set_cpuid(void) {
  get_cpuid(cpuid);
};
