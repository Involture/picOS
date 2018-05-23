#ifndef _KERNEL_SHELL_CMDS
#define _KERNEL_SHELL_CMDS

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <kernel/filesystem.h>

void p16(uint16_t n) {
	uint8_t a = n / 256;
	uint8_t b = n % 256;
	printf("%x", a);
	printf("%x", b);
}

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

	char* e = filesystem_find_fn_from_id(b);
	printf("filename : %s\n", e);

	// fs_correct_fn(b, e);

	// uint8_t c = 65;
	// filesystem_write_file_byte(b, c, true, 0);
	// uint8_t d;
	// // b = filesystem_delete_file(b);
	// d = filesystem_read_file_byte(b, 0);
	// printf("%c\n", (char) d);

	// if (d == c) {
	// 	printf("hell yeah\n");
	// }


	return 0;
}

int cmd_cd (char* a) {
	uint16_t b = filesystem_find_id_from_fn(a);
	if (b != 0) {
		filesystem_change_dir(b);
		printf("%s\n", filesystem_find_fn_from_id(filesystem_get_cwd()));;
	} else {
		printf("not found\n");
	}
	return 0;
}

int cmd_ls (char *a) {
	uint16_t* b = filesystem_dir_read_elements(filesystem_get_cwd());
	uint16_t c = b[0];
	// p16(c);
	char* temp_filename = "";
	for (int i = 0; i < c; ++i)
	{
		temp_filename = filesystem_find_fn_from_id(b[1+i]);
		// printf("\n%s", temp_filename);
	}

	// printf("!");
	// filesystem_read_file(filesystem_get_cwd());
	// printf("#");
	fs_debug();

	return 0;
}

int cmd_cat (char* a) {
	uint16_t b = filesystem_find_id_from_fn(a);
	printf("shit\n");
	if (b != 0) {
		filesystem_read_file(b);
	} else {
		if (strlen(a) == 0) {
			filesystem_read_file(filesystem_get_cwd());
		} else {
			printf("not found\n");
		}
	}
	return 0;
}

int cmd_pwd (char* a) {
	char* b = filesystem_find_fn_from_id(filesystem_get_cwd());
	printf("%s\n", b);
	return 0;
}

int cmd_rm (char* a) {
	uint16_t b = filesystem_find_id_from_fn(a);
	filesystem_clear_file(b);

	return 0;
}

int cmd_rmdir (char* a) {
	uint16_t b = filesystem_find_id_from_fn(a);
	filesystem_clear_dir(b);

	return 0;
}

int cmd_debug (char* a) {
	fs_debug_malloc();

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
	{ "mkdir", cmd_mkdir },
	{ "cd", cmd_cd },
	{ "ls", cmd_ls },
	{ "cat", cmd_cat },
	{ "pwd", cmd_pwd },
	{ "rm", cmd_rm },
	{ "rmdir", cmd_rmdir },
	{ "debug", cmd_debug }
};

#endif
