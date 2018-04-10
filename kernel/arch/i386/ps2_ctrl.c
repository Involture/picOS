#include <kernel/ps2_ctrl.h>
#include <kernel/port.h>
#include <stdio.h>
#include <stdbool.h>

static void perror(void) {
  printf("PS/2 controller init error : ");
};

#define TIMEOUT 10000
static int timer;

static bool wait(void) {
  timer++;
  if (timer == TIMEOUT) {
    perror();
    puts("Timeout");
    return false;
  };
  return true;
};

static void outb_data(char byte) {
  outb(PS2_CTRL_DATA_PORT, byte);
};

static void outb_cmd(char byte) {
  outb(PS2_CTRL_CMD_PORT, byte);
};

static char inb_data(void) {
  return inb(PS2_CTRL_DATA_PORT);
};

static char get_status(void) {
  return inb(PS2_CTRL_CMD_PORT);
};

static void outb_block_cmd(char byte) {
  timer = 0;
  while (get_status() & PS2_CTRL_INPUT_BUF)
    wait();
  outb_cmd(byte);
};

static void outb_block_data(char byte) {
  timer = 0;
  while (get_status() & PS2_CTRL_INPUT_BUF)
    wait();
  outb_data(byte);
};

static char inb_block_data(void) {
  while (! (get_status() & PS2_CTRL_OUTPUT_BUF))
    wait();
  return inb_data();
}


int ps2_ctrl_init(void) {
  puts("Disabling ports");
  outb_cmd(PS2_CTRL_CMD_DSBL_P1); // Dsbl ports so they dont interfere
  outb_cmd(PS2_CTRL_CMD_DSBL_P2); // with initialization

  timer = 0;                            // Flush the output buffer
  while ((get_status() & PS2_CTRL_INPUT_BUF) | (timer < TIMEOUT)) {
    timer++;
    printf("time : %x |", timer);
    printf("data_received : %x\n",inb_data());                           
  };
  printf("Ps2 statut after flush : %x\n", get_status());
  printf("Timer after flush : %x\n", timer);

  // Checking if the port are well disabled
  inb_block_data();                     // Should block whatever the inputs
  perror();                             // on keyboards
  puts("Ports were not disabled correctly !!!");

  puts("Disabling interrupts");
  outb_block_cmd(PS2_CTRL_CMD_GET_CONF);// Get the configuration
  char conf = inb_block_data();         // Change configuration
  conf &= !PS2_CTRL_CONF_I1;            // Disable interrupts so nothing
  conf &= !PS2_CTRL_CONF_I2;            // interfere with initialization
  conf &= !PS2_CTRL_CONF_TRSL;          // Disable translation to scancodeset 1
  outb_block_cmd(PS2_CTRL_CMD_WRITE_CONF);
  outb_block_data(conf);

  puts("Running global tests");
  outb_block_cmd(PS2_CTRL_CMD_TEST);    // Run global test
  char response = inb_block_data();
  if (!(response == 0x55)) {
    perror();
    puts("Global test failed");
    printf("respons %x\n", response);
  };

  puts("Checking if port 2 is available");
  outb_block_cmd(PS2_CTRL_CMD_ENBL_P2); // Enable P2 to see if its available
  outb_block_cmd(PS2_CTRL_CMD_GET_CONF);// Get config again
  conf = inb_block_data();
  if (conf & PS2_CTRL_CONF_CLK2) {      // If clock of P2 is disable, second
                                        // port is not available
    perror();
    puts("Port 2 unavailable");
  };
  outb_block_cmd(PS2_CTRL_CMD_DSBL_P2); // Disable P2 again

  puts("Testing first port");
  outb_block_cmd(PS2_CTRL_CMD_TEST_P1); // Test the first port
  if (!inb_block_data()) {
    perror();
    puts("Port 1 test failed");
  }
  puts("Testing second port");
  outb_block_cmd(PS2_CTRL_CMD_TEST_P2); // Test the second port
  if (!inb_block_data()) {
    perror();
    puts("Port 2 test failed");
  }

  puts("Enabling ports");
  outb_block_cmd(PS2_CTRL_CMD_ENBL_P1); // Enable ports
  outb_block_cmd(PS2_CTRL_CMD_ENBL_P2);

  puts("Enabling interrupts");
  outb_block_cmd(PS2_CTRL_CMD_GET_CONF);// Set interrupts and translation again
  conf = (inb_block_data());
  conf |= PS2_CTRL_CONF_I1;
  conf |= PS2_CTRL_CONF_I2;
  conf |= !PS2_CTRL_CONF_TRSL;
  outb_block_cmd(PS2_CTRL_CMD_WRITE_CONF);
  outb_block_data(conf);

  return 0;
};

void ps2_ctrl_outb1(char byte) {
  outb_block_cmd(PS2_CTRL_CMD_WRITE_P1);
  outb_block_data(byte);
};

void ps2_ctrl_outb2(char byte) {
  outb_block_cmd(PS2_CTRL_CMD_WRITE_P2);
  outb_block_data(byte);
};

char ps2_ctrl_inb(void) {
  return inb_data();
};
