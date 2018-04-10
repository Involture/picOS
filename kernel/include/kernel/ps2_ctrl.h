#ifndef _KERNEL_PS2_CTRL
#define _KERNEL_PS2_CTRL

enum ps2_ctrl_port {
  PS2_CTRL_DATA_PORT = 0x60,
  PS2_CTRL_CMD_PORT = 0x64,
};

enum ps2_ctrl_status {
  PS2_CTRL_OUTPUT_BUF = 1 << 0, // Ouput buffer is full
  PS2_CTRL_INPUT_BUF  = 1 << 1, // Input buffer is full
  PS2_CTRL_SYS_FLAG   = 1 << 2, // Set if the controller passed tests on setup
  PS2_CTRL_DEST       = 1 << 3, // Set if the data in input buffer is for ctrl
  PS2_CTRL_TIME_OUT   = 1 << 6, // Set if time out error
  PS2_CTRL_PARITY     = 1 << 7, // Set if parity error
};

enum ps2_ctrl_conf {
  PS2_CTRL_CONF_I1    = 1 << 0, // Enable interrupt for PS/2 port 1
  PS2_CTRL_CONF_I2    = 1 << 1, // Enable interrupt for PS/2 port 2
  PS2_CTRL_CONF_SYSOK = 1 << 2, // System passed the init checkup
  PS2_CTRL_CONF_CLK1  = 1 << 4, // First port clock disabled
  PS2_CTRL_CONF_CLK2  = 1 << 5, // Second port clock disabled
  PS2_CTRL_CONF_TRSL  = 1 << 6, // First port translation enabled
};

enum ps2_ctrl_cmd {
  PS2_CTRL_CMD_GET_CONF   = 0x20,   // Get the controller configuration byte
  PS2_CTRL_CMD_WRITE_CONF = 0x60,   // Write controller configuration byte
  PS2_CTRL_CMD_ENBL_P2    = 0xA7,   // Enable the second PS/2 port
  PS2_CTRL_CMD_DSBL_P2    = 0xA8,   // Disable the second PS/2 port
  PS2_CTRL_CMD_TEST_P2    = 0xA9,   // Test second port. 0x00 if test passed
  PS2_CTRL_CMD_TEST       = 0xAA,   // Global test. Return 0x55 if test passed
  PS2_CTRL_CMD_TEST_P1    = 0xAB,   // Test first port. 0x00 if test passed
  PS2_CTRL_CMD_ENBL_P1    = 0xAE,   // Enable the first PS/2 port
  PS2_CTRL_CMD_DSBL_P1    = 0xAD,   // Disable the first PS/2 port
  PS2_CTRL_CMD_READ_COP   = 0xD0,   // Read controller output port
  PS2_CTRL_CMD_WRITE_COP  = 0xD1,   // Write next byte to controller output port
  PS2_CTRL_CMD_WRITE_P1   = 0xD2,   // Write next b to first out buffer
  PS2_CTRL_CMD_WRITE_P2   = 0xD3,   // Write next b to second out buffer
};

enum ps2_ctrl_cot {
  PS2_CTRL_COT_A20        = 1 << 1, // A20 Gate
  PS2_CTRL_COT_CLK2       = 1 << 2, // Second port clock
  PS2_CTRL_COT_DATA2      = 1 << 3, // Second port data
  PS2_CTRL_COT_OUT1       = 1 << 4, // Output full of first port
  PS2_CTRL_COT_OUT2       = 1 << 5, // Output full of second port
  PS2_CTRL_COT_CLK1       = 1 << 6, // First port clock
  PS2_CTRL_COT_DATA1      = 1 << 7, // First port data
};

void ps2_ctrl_outb1(char);
void ps2_ctrl_outb2(char);
int ps2_ctrl_init(void); 
char ps2_ctrl_inb(void);

#endif
