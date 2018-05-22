#ifndef _KERNEL_SHELL_CMDS
#define _KERNEL_SHELL_CMDS

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <kernel/filesystem.h>

// declaration of functions corresponding to shell commands
int cmd_echo (char* a) {
	printf("%s\n", a);
	return 0;
}

int cmd_false (char* a) {
	return 0;
}
int cmd_true (char* a) {
	return 0;
}
int cmd_mkdir (char* a) {
	uint16_t b = filesystem_new_file(a, true);

	uint8_t c = 42;
	filesystem_write_file_byte(b, c, true, 0);
	uint8_t d;
	d = filesystem_read_file_byte(b, 0);

	if (d == c) {
		printf("hell yeah\n");
	}


	return 0;
}

// struct to cope with these functions
static struct {
	char* cmd_kwd;
	int (*cmd_fct)(char*);
} cmds_map [] = {
	{ "echo", cmd_echo },
	{ "false", cmd_false },
	{ "true", cmd_true },
	{ "mkdir", cmd_mkdir }
};

#endif
