#ifndef _KERNEL_SHELL_CMDS
#define _KERNEL_SHELL_CMDS

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

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
int cmd_dirname (char* a) {
	// size_t len = strlen(a);
	// char b[len] = {0};
	// size_t i;
	// bool c = false;
	// for (i = 0; i < len; ++i)
	// {
	// 	/* code */
	// }

	// printf("%s\n", b);
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
	{ "dirname", cmd_dirname }
};

#endif
