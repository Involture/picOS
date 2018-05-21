#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <kernel/tty.h>
#include <kernel/tty_ext.h>
#include <kernel/ps2_ctrl.h>
#include <kernel/ps2_kbd.h>
#include <kernel/ps2_kbd_kmp.h>
// #include <kernel/shell.h>

#define SHELL_CMD_MAX_LENGTH 65536
void shell_exec(char*, size_t);

static unsigned char ps2_kbd_kmp_history[PS2_KBD_KMP_HISTORY_SIZE] = {0};
static unsigned char ps2_kbd_kmp_keyboard_state[256] = {0};
static unsigned char ps2_kbd_kmp_capslock_state = 0;
static unsigned char ps2_kbd_kmp_pos = 0;
static unsigned char ps2_kbd_kmp_pos_last_cmd = PS2_KBD_KMP_HISTORY_SIZE - 1;
static unsigned char ps2_kbd_kmp_pos_shift;

static unsigned char shell_mode = 0;
static unsigned char shell_last_cmd_pos = 255;
static char shell_last_cmd[SHELL_CMD_MAX_LENGTH] = {0};

void ps2_kbd_kmp_load(unsigned char x) {
    // gcc prevents a negative index from being used I think
    ps2_kbd_kmp_history[ps2_kbd_kmp_pos % PS2_KBD_KMP_HISTORY_SIZE] = x;
    ps2_kbd_kmp_is_cmd(ps2_kbd_kmp_history);
    ps2_kbd_kmp_pos += 1;
    ps2_kbd_kmp_pos %= PS2_KBD_KMP_HISTORY_SIZE;
};

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
    while (i <= (ps2_kbd_kmp_pos_shift - 1) && i <= 2) {
        j = ps2_kbd_kmp_pos - i;
        // necessary in order to cope correctly with unsigned chars
        while (j > PS2_KBD_KMP_HISTORY_SIZE) {
            j -= PS2_KBD_KMP_HISTORY_SIZE;
        }
        last_cmd[i] = history[j];
        i += 1;
    };

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

    char last_cmd_chr = '\0';
    char last_cmd_chr1 = '\0';
    char last_cmd_chr2 = '\0';
    char last_cmd_chr3 = '\0';
    unsigned char kc = 255;
    unsigned char last_cmd_is_pressed = 0;
    unsigned char is_cmd = 1;
    unsigned char produces_output = 1;

    #include "ps2_kbd_kmp_switch.c"

    if (last_cmd_is_pressed == 1) {
        ps2_kbd_kmp_keyboard_state[kc] = 1;
    } else {
        ps2_kbd_kmp_keyboard_state[kc] = 0;
    }

    unsigned char dc = 0;

    // capslock
    if (dc == 0 && ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_CAPSLOCK] == 1) {
        ps2_kbd_kmp_capslock_state = (ps2_kbd_kmp_capslock_state == 1) ? 0 : 1;
        ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_CAPSLOCK] = 0;
        dc = 1;
    }

    // shell mode
    if (
        dc == 0
    && shell_mode == 0
    &&  ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_CTRLL] == 1
    &&  ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_SHIFTL] == 1
    &&  ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_S] == 1
    ) {
        ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_CTRLL] = 0;
        ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_SHIFTL] = 0;
        ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_S] = 0;

        if (shell_mode == 0) {
            printf("\nshell mode - enabled\n>>>");
        }
        shell_mode = 1;
        shell_last_cmd_pos = 0;
        // shell_last_cmd = {0};
        produces_output = 0;
        dc = 1;
    }


    unsigned char kbd_mode = ps2_kbd_kmp_capslock_state;
    if (dc == 0
        && (ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_SHIFTL] == 1 ||  ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_SHIFTR] == 1))
    {
        kbd_mode = (kbd_mode == 1) ? 0 : 1;
        dc = 1;
    } else {
        if (ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_ALTR] == 1) {
            kbd_mode = 2;
            dc = 1;
        }
    }

    if (dc == 0 && ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_ENTER] == 1) {
        if (shell_mode == 1) {
            printf("\n");
            shell_exec(shell_last_cmd, shell_last_cmd_pos);

            for (int i = 0; i < SHELL_CMD_MAX_LENGTH; ++i) {
                shell_last_cmd[i] = 0;
            }
            shell_mode = 0;
            ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_ENTER] = 0;
            produces_output = 0;
            dc = 1;
        }
    }

    if (dc == 0 && ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_BACKSPACE] == 1) {
        if (shell_mode == 1) {
            if (shell_last_cmd_pos != 0){
                tty_ext_rm_last_char();
                shell_last_cmd_pos -= 1;
                shell_last_cmd[shell_last_cmd_pos] = 0;
            }
        } else {
            tty_ext_rm_last_char();
        }
        ps2_kbd_kmp_keyboard_state[PS2_KBD_KMP_BACKSPACE] = 0;
        produces_output = 0;
        dc = 1;
    }



    if (is_cmd == 1) {
        ps2_kbd_kmp_pos_last_cmd = ps2_kbd_kmp_pos;
        switch (kbd_mode) {
            case 0:
                last_cmd_chr = last_cmd_chr1;
                break;
            case 1:
                last_cmd_chr = last_cmd_chr2;
                break;
            case 2:
                last_cmd_chr = last_cmd_chr3;
                break;
            default:
                break;
        }

        if (produces_output == 1 && last_cmd_is_pressed == 1) {
            if (last_cmd_chr != '\0') {
                printf("%c", last_cmd_chr);
            }

            if (shell_mode == 1) {
                if (produces_output == 1 && last_cmd_chr != '\0') {
                    shell_last_cmd[shell_last_cmd_pos] = last_cmd_chr;
                    shell_last_cmd_pos += 1;
                }
            }
        }

    }
};

