#ifndef _KERNEL_PS2_KBD_KMP
#define _KERNEL_PS2_KBD_KMP

#define PS2_KBD_KMP_HISTORY_SIZE 32

void ps2_kbd_kmp_load(unsigned char);
void ps2_kbd_kmp_is_cmd(unsigned char*);

#endif
