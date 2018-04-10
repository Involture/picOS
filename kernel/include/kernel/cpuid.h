#include <stdint.h>
#include <stdbool.h>

enum {
  CPUID_FEAT_EDX_FPU        = 1 << 0 ,
  CPUID_FEAT_EDX_VME        = 1 << 1 ,
  CPUID_FEAT_EDX_DE         = 1 << 2 ,
  CPUID_FEAT_EDX_PSE        = 1 << 3 ,
  CPUID_FEAT_EDX_TSC        = 1 << 4 ,
  CPUID_FEAT_EDX_MSR        = 1 << 5 ,
  CPUID_FEAT_EDX_PAE        = 1 << 6 ,
  CPUID_FEAT_EDX_MCE        = 1 << 7 ,
  CPUID_FEAT_EDX_CX8        = 1 << 8 ,
  CPUID_FEAT_EDX_APIC       = 1 << 9 ,
  CPUID_FEAT_EDX_SEP        = 1 << 11,
  CPUID_FEAT_EDX_MTRR       = 1 << 12,
  CPUID_FEAT_EDX_PGE        = 1 << 13,
  CPUID_FEAT_EDX_MCA        = 1 << 14,
  CPUID_FEAT_EDX_CMOV       = 1 << 15,
  CPUID_FEAT_EDX_PAT        = 1 << 16,
  CPUID_FEAT_EDX_PSE36      = 1 << 17,
  CPUID_FEAT_EDX_PSN        = 1 << 18,
  CPUID_FEAT_EDX_CLF        = 1 << 19,
  CPUID_FEAT_EDX_DTES       = 1 << 21,
  CPUID_FEAT_EDX_ACPI       = 1 << 22,
  CPUID_FEAT_EDX_MMX        = 1 << 23,
  CPUID_FEAT_EDX_FXSR       = 1 << 24,
  CPUID_FEAT_EDX_SSE        = 1 << 25,
  CPUID_FEAT_EDX_SSE2       = 1 << 26,
  CPUID_FEAT_EDX_SS         = 1 << 27,
  CPUID_FEAT_EDX_HTT        = 1 << 28,
  CPUID_FEAT_EDX_TM1        = 1 << 29,
  CPUID_FEAT_EDX_IA64       = 1 << 30,
  CPUID_FEAT_EDX_PBE        = 1 << 31
};

uint32_t* cpuid;
void cpuid_set(void);
extern uint32_t get_cpuid(uint32_t*);
bool cpuid_has_feat(int);
