#include <stdint.h>
#include <stdbool.h>

uint32_t* cpuid;
void set_cpuid(void);
extern uint32_t get_cpuid(uint32_t*);
extern bool check_cpuid(void);
