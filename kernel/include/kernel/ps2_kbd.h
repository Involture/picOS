#ifndef _KERNEL_PS2_KBD_H
#define _KERNEL_PS2_KBD_H

#define PS2_KBD_CMD_LED             0xED
#define PS2_KBD_CMD_ECHO            0xEE
#define PS2_KBD_CMD_GET_SCSET       0xF0
#define PS2_KBD_CMD_ID              0xF2
#define PS2_KBD_CMD_AUTOREPEAT      0xF3
#define PS2_KBD_CMD_ENBL            0xF4
#define PS2_KBD_CMD_DSBL            0xF5
#define PS2_KBD_CMD_DEFAULT         0xF6
#define PS2_KBD_CMD_ALL_TA_MODE     0xF7
#define PS2_KBD_CMD_ALL_MR_MODE     0xF8
#define PS2_KBD_CMD_ALL_M_MODE      0xF9
#define PS2_KBD_CMD_ALL_TAMR_MODE   0xFA
#define PS2_KBD_CMD_KEY_TA_MODE     0xFB
#define PS2_KBD_CMD_KEY_MR_MODE     0xFC
#define PS2_KBD_CMD_KEY_M_MODE      0xFD
#define PS2_KBD_CMD_RESEND          0xFE
#define PS2_KBD_CMD_RESET           0xFF

#define PS2_KBD_ERR1                0x00
#define PS2_KBD_ERR2                0xFF
#define PS2_KBD_TEST_OK             0xAA
#define PS2_KBD_ECHO                0xEE
#define PS2_KBD_ACK                 0xFA
#define PS2_KBD_TEST_FAIL1          0xFC
#define PS2_KBD_TEST_FAIL2          0xFD
#define PS2_KBD_RESEND              0xFE

#define PS2_KBD_QUEUE_SIZE 10

int ps2_kbd_timeout;
int ps2_kbd_tries;

#endif
