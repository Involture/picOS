#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <kernel/tty.h>
#include <kernel/tty_ext.h>
#include <kernel/ps2_ctrl.h>
#include <kernel/ps2_kbd.h>
#include <kernel/ps2_kbd_kmp.h>

static unsigned char ps2_kbd_kmp_history[PS2_KBD_KMP_HISTORY_SIZE] = {0};
static unsigned char ps2_kbd_kmp_keyboard_state[256] = {0};
static unsigned char ps2_kbd_kmp_capslock_state = 0;

unsigned char ps2_kbd_kmp_pos = 0;
unsigned char ps2_kbd_kmp_pos_last_cmd = PS2_KBD_KMP_HISTORY_SIZE - 1;
unsigned char ps2_kbd_kmp_pos_shift;

void ps2_kbd_kmp_load(unsigned char x) {
    // gcc prevents a negative index from being used I think
	ps2_kbd_kmp_history[ps2_kbd_kmp_pos % PS2_KBD_KMP_HISTORY_SIZE] = x;
	ps2_kbd_kmp_is_cmd(&ps2_kbd_kmp_history);
	ps2_kbd_kmp_pos += 1;
	ps2_kbd_kmp_pos %= PS2_KBD_KMP_HISTORY_SIZE;
};

void pli(unsigned long int a) {
	unsigned char b1;
	unsigned char b2;
	unsigned char b3;
	unsigned char b4;
	unsigned char b5;
	unsigned char b6;
	unsigned char b7;
	unsigned char b8;
	b1 = a;
	b2 = a >> 4;
	b3 = a >> 8;
	b4 = a >> 12;
	b5 = a >> 16;
	b6 = a >> 20;
	b7 = a >> 24;
	b8 = a >> 28;
	b1 = b1 % 256;
	b2 = b2 % 256;
	b3 = b3 % 256;
	b4 = b4 % 256;
	b5 = b5 % 256;
	b6 = b6 % 256;
	b7 = b7 % 256;
	b8 = b8 % 256;
	printf("%x", b8);
	printf("%x", b7);
	printf("%x", b6);
	printf("%x", b5);
	printf("%x", b4);
	printf("%x", b3);
	printf("%x", b2);
	printf("%x", b1);
	printf("\n");
}

void ps2_clear() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void ps2_kbd_kmp_is_cmd(unsigned char* history) {
	unsigned char last_cmd[3] = {0};

	ps2_kbd_kmp_pos_shift = ps2_kbd_kmp_pos - ps2_kbd_kmp_pos_last_cmd;
    // necessary in order to cope correctly with unsigned chars
    while (ps2_kbd_kmp_pos_shift > PS2_KBD_KMP_HISTORY_SIZE) {
        ps2_kbd_kmp_pos_shift -= PS2_KBD_KMP_HISTORY_SIZE;
    }

    unsigned char i = 0;
    unsigned char j = 0;
    // printf("Buffer:");
    while (i <= (ps2_kbd_kmp_pos_shift - 1) && i <= 2) {
        j = ps2_kbd_kmp_pos - i;
        // necessary in order to cope correctly with unsigned chars
        while (j > PS2_KBD_KMP_HISTORY_SIZE) {
            j -= PS2_KBD_KMP_HISTORY_SIZE;
        }
        // printf("%x: ", j);
        last_cmd[i] = history[j];
        // printf("%x ", last_cmd[i]);
        i += 1;
    };
    // printf("\n");
    unsigned char a = 0x00;
    unsigned char b = 0x00;
    unsigned char c = 0x00;
    switch (ps2_kbd_kmp_pos_shift) {
        case 1:
            a = 0x00;
            b = 0x00;
            c = last_cmd[0];
            break;
        case 2:
            a = 0x00;
            b = last_cmd[1];
            c = last_cmd[0];
            break;
        case 3:
            a = last_cmd[2];
            b = last_cmd[1];
            c = last_cmd[0];
            break;
        default:
            a = 0x00;
            b = 0x00;
            c = 0x00;
    }

    // printf("%x ", a);
    // printf("%x ", b);
    // printf("%x\n", c);



    char* last_cmd_name = "";
    char* last_cmd_chr1 = "";
    char* last_cmd_chr2 = "";
    char* last_cmd_chr3 = "";
    unsigned char kc = 255;
    unsigned char last_cmd_is_pressed = 1;
    unsigned char is_cmd = 1;

    #include "ps2_kbd_kmp_switch.c"

    if (last_cmd_is_pressed == 1) {
        // printf("%x\n", kc);
        ps2_kbd_kmp_keyboard_state[kc] = 1;
        if (kc == PS2_KBD_KMP_CAPSLOCK) {
            ps2_kbd_kmp_capslock_state = (ps2_kbd_kmp_capslock_state == 1) ? 0 : 1;
        }
    } else {
        ps2_kbd_kmp_keyboard_state[kc] = 0;
    }


    unsigned kbd_mode = ps2_kbd_kmp_capslock_state;
    if ((ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_SHIFTL] == 1) || (ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_SHIFTR] == 1)) {
        kbd_mode = 1 - kbd_mode;
    } else {
        if (ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_ALTR] == 1) {
            kbd_mode = 2;
        }
    }

    if (ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_BACKSPACE] == 1) {
        tty_ext_rm_last_char();
        ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_BACKSPACE] = 0;
    }

    // printf("Pos: %x ; ", ps2_kbd_kmp_pos);
    // printf("shift: %x ;", ps2_kbd_kmp_pos_shift);
    // printf("last pos: %x\n", ps2_kbd_kmp_pos_last_cmd);

    // printf("%x\n", is_cmd);
    // printf("History:");
    // for (int i = 0; i < PS2_KBD_KMP_HISTORY_SIZE; ++i)
    // {
    //     printf("%x ", history[i]);
    // }
    // printf("\n");
    if (is_cmd == 1) {
        ps2_kbd_kmp_pos_last_cmd = ps2_kbd_kmp_pos;
        // printf("Key: %s\n", last_cmd_name);
        switch (kbd_mode) {
            case 0:
                printf("%s", last_cmd_chr1);
                break;
            case 1:
                printf("%s", last_cmd_chr2);
                break;
            case 2:
                printf("%s", last_cmd_chr3);
                break;
            default:
                printf("%s", "...");
        }
        // printf("%s", last_cmd_chr);
        // printf("Is pressed: %x\n", last_cmd_is_pressed);
    }
    //  else {
    //     printf("No key recognized\n");
    // }

    // printf("%x\n", s);
    // // char a = rslt[ps2_kbd_kmp_pos];
    // // char b = rslt[(ps2_kbd_kmp_pos - 1) % PS2_KBD_KMP_HISTORY_SIZE];
    // // char c = rslt[(ps2_kbd_kmp_pos - 2) % PS2_KBD_KMP_HISTORY_SIZE];

    // // printf("%x\n", a);s
    // // printf("%x\n", b);
    // // printf("%x\n", c);
    // // printf("%x\n", PS2_KBD_KMP_HISTORY_SIZE);
    // printf("\n");
    // printf("\n");
    // printf("%x\n", ps2_kbd_kmp_pos);
    // printf("\n");
};

// void ps2_kbd_kmp_action(unsigned char* kbd_state) {

// };