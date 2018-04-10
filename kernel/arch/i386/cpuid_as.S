.att_syntax noprefix

.section .text
.global get_cpuid
.type get_cpuid, @function

# uint32_t get_cpuid(uint32_t* cpuid)
get_cpuid :
  mov $0x1, eax
  cpuid
  mov 4(esp), ecx
  mov edx, (ecx)
  ret
