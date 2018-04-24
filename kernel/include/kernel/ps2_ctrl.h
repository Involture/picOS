#ifndef _KERNEL_PS2_CTRL_H
#define _KERNEL_PS2_CTRL_H

#define PS2_CTRL_DATA_PORT 0x60
#define PS2_CTRL_CMD_PORT 0x64

#define PS2_CTRL_OUTPUT_BUF (1 << 0) // Ouput buffer is full
#define PS2_CTRL_INPUT_BUF  (1 << 1) // Input buffer is full
#define PS2_CTRL_SYS_FLAG   (1 << 2) // Controller passed tests on setup
#define PS2_CTRL_DEST       (1 << 3) // Data in input buffer is for ctrl
#define PS2_CTRL_TIME_OUT   (1 << 6) // Set if time out error
#define PS2_CTRL_PARITY     (1 << 7) // Set if parity error

#define PS2_CTRL_CONF_I1    (1 << 0) // Enable interrupt for PS/2 port 1
#define PS2_CTRL_CONF_I2    (1 << 1) // Enable interrupt for PS/2 port 2
#define PS2_CTRL_CONF_SYSOK (1 << 2) // System passed the init checkup
#define PS2_CTRL_CONF_CLK1  (1 << 4) // First port clock disabled
#define PS2_CTRL_CONF_CLK2  (1 << 5) // Second port clock disabled
#define PS2_CTRL_CONF_TRSL  (1 << 6) // First port translation enabled

#define PS2_CTRL_CMD_GET_CONF   0x20   // Get the controller configuration byte
#define PS2_CTRL_CMD_WRITE_CONF 0x60   // Write controller configuration byte
#define PS2_CTRL_CMD_ENBL_P2    0xA8   // Enable the second PS/2 port
#define PS2_CTRL_CMD_DSBL_P2    0xA7   // Disable the second PS/2 port
#define PS2_CTRL_CMD_TEST_P2    0xA9   // Test second port. 0x00 if test passed
#define PS2_CTRL_CMD_TEST       0xAA   // Global test. Return 0x55 if passed
#define PS2_CTRL_CMD_TEST_P1    0xAB   // Test first port. 0x00 if test passed
#define PS2_CTRL_CMD_ENBL_P1    0xAE   // Enable the first PS/2 port
#define PS2_CTRL_CMD_DSBL_P1    0xAD   // Disable the first PS/2 port
#define PS2_CTRL_CMD_READ_COP   0xD0   // Read controller output port
#define PS2_CTRL_CMD_WRITE_COP  0xD1   // Write next byte to ctrl output port
#define PS2_CTRL_CMD_WRITE_P1   0xD2   // Write next b to first out buffer
#define PS2_CTRL_CMD_WRITE_P2   0xD3   // Write next b to second out buffer

#define PS2_CTRL_COT_A20        (1 << 1) // A20 Gate
#define PS2_CTRL_COT_CLK2       (1 << 2) // Second port clock
#define PS2_CTRL_COT_DATA2      (1 << 3) // Second port data
#define PS2_CTRL_COT_OUT1       (1 << 4) // Output full of first port
#define PS2_CTRL_COT_OUT2       (1 << 5) // Output full of second port
#define PS2_CTRL_COT_CLK1       (1 << 6) // First port clock
#define PS2_CTRL_COT_DATA1      (1 << 7) // First port data

// The timeout for commands send to the ps2_ctrl
int ps2_ctrl_timeout;
// Output byte to the first ps2 device
void ps2_ctrl_outb1(char);
// Output byte to the second ps2 device
void ps2_ctrl_outb2(char);
// Initialize the ps2_ctrl
void ps2_ctrl_init(void); 
// Read byte from the ps2_ctrl
char ps2_ctrl_inb(void);

#endif
