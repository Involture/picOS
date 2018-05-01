#ifndef _KERNEL_PS2_KBD_KMP
#define _KERNEL_PS2_KBD_KMP

#define PS2_KBD_KMP_HISTORY_SIZE 8

#define PS2_KBD_KMP_SHIFTL 128
#define PS2_KBD_KMP_SHIFTR 140
#define PS2_KBD_KMP_ALTR 165
#define PS2_KBD_KMP_BACKSPACE 45

#define PS2_KBD_KMP_CAPSLOCK 96

void ps2_kbd_kmp_load(unsigned char);
void ps2_kbd_kmp_is_cmd(unsigned char*);
// void ps2_kbd_kmp_action(unsigned char*);

#endif
