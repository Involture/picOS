#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <kernel/ps2_ctrl.h>

#include <kernel/ps2_kbd.h>

static char cmd_queue[PS2_KBD_QUEUE_SIZE];

static bool need_data(uint8_t cmd) {
  return 
     ((cmd != PS2_KBD_CMD_ECHO)          && (cmd != PS2_KBD_CMD_ID)          &&
      (cmd != PS2_KBD_CMD_ENBL)          && (cmd != PS2_KBD_CMD_DSBL)        &&
      (cmd != PS2_KBD_CMD_DEFAULT)       && (cmd != PS2_KBD_CMD_ALL_TA_MODE) &&
      (cmd != PS2_KBD_CMD_ALL_MR_MODE)   && (cmd != PS2_KBD_CMD_ALL_M_MODE)  &&
      (cmd != PS2_KBD_CMD_ALL_TAMR_MODE) && (cmd != PS2_KBD_CMD_RESEND)      &&
      (cmd != PS2_KBD_CMD_RESET)
     );
}

static int send(uint8_t cmd, uint8_t data) {
  ps2_ctrl_timeout = ps2_kbd_timeout;
  ps2_ctrl_outb1(cmd);
  if (need_data(cmd))
    ps2_ctrl_outb1(data);
  uint8_t response;
  while ((PS2_KBD_RESEND) == (response = ps2_ctrl_inb()));
  if (response != PS2_KBD_ACK)
    return 1;
  return 0;
}
