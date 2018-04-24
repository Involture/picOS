#include <stdint.h>
#include <stdbool.h>

#define CPUID_FEAT_EDX_FPU    (1 << 0)
#define CPUID_FEAT_EDX_VME    (1 << 1)
#define CPUID_FEAT_EDX_DE     (1 << 2)
#define CPUID_FEAT_EDX_PSE    (1 << 3)
#define CPUID_FEAT_EDX_TSC    (1 << 4)
#define CPUID_FEAT_EDX_MSR    (1 << 5)
#define CPUID_FEAT_EDX_PAE    (1 << 6)
#define CPUID_FEAT_EDX_MCE    (1 << 7)
#define CPUID_FEAT_EDX_CX8    (1 << 8)
#define CPUID_FEAT_EDX_APIC   (1 << 9)
#define CPUID_FEAT_EDX_SEP    (1 << 11)
#define CPUID_FEAT_EDX_MTRR   (1 << 12)
#define CPUID_FEAT_EDX_PGE    (1 << 13)
#define CPUID_FEAT_EDX_MCA    (1 << 14)
#define CPUID_FEAT_EDX_CMOV   (1 << 15)
#define CPUID_FEAT_EDX_PAT    (1 << 16)
#define CPUID_FEAT_EDX_PSE36  (1 << 17)
#define CPUID_FEAT_EDX_PSN    (1 << 18)
#define CPUID_FEAT_EDX_CLF    (1 << 19)
#define CPUID_FEAT_EDX_DTES   (1 << 21)
#define CPUID_FEAT_EDX_ACPI   (1 << 22)
#define CPUID_FEAT_EDX_MMX    (1 << 23)
#define CPUID_FEAT_EDX_FXSR   (1 << 24)
#define CPUID_FEAT_EDX_SSE    (1 << 25)
#define CPUID_FEAT_EDX_SSE2   (1 << 26)
#define CPUID_FEAT_EDX_SS     (1 << 27)
#define CPUID_FEAT_EDX_HTT    (1 << 28)
#define CPUID_FEAT_EDX_TM1    (1 << 29)
#define CPUID_FEAT_EDX_IA64   (1 << 30)
#define CPUID_FEAT_EDX_PBE    (1 << 31)

// A pointer to the cpuid, can be accessed globally
uint32_t* cpuid;
// Get the cpuid from the cpu and set it
void cpuid_set(void);
// Perform bit wise and with the cpuid to determine if a feature is enabled
bool cpuid_has_feat(uint32_t);
