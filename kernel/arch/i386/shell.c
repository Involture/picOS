#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <kernel/shell.h>
#include <kernel/shell_cmds.h>
#include <kernel/filesystem.h>

static bool shell_lexical_analysis_is_kwd(char* shell_p_kwd) {
	bool found;
	for (int i = 0; i < SHELL_KWDS_NMB; ++i)
	{
		found = true;
		for (int j = 0; j < SHELL_KWD_MAX_LENGTH; ++j)
		{
			if (shell_p_kwd[j] != shell_kwds[i*SHELL_KWD_MAX_LENGTH + j]) {
				found = false;
			}
		}
		if (found) {
			return true;
		}
	}
	return false;
}

static int shell_lexical_analysis_dispatcher(char* shell_cmd_kwd, char* shell_cmd_params) {
	unsigned int i;
	int result;
	for (i = 0; i < (sizeof(cmds_map) / sizeof(cmds_map[0])); ++i)
	{
		if (! strcmp(cmds_map[i].cmd_kwd, shell_cmd_kwd) && cmds_map[i].cmd_fct) {
			result = cmds_map[i].cmd_fct(shell_cmd_params);
			return result;
		}
	}
	fs_debug();
	printf("This command is supposed to be implemented.\n");
	printf("However, it is recommended that your test of this OS does not rely on this functionality.\n");
	return -1;
}

static int shell_lexical_analysis(char* shell_cmd, size_t shell_cmd_length) {
	bool a;
	char shell_cmd1[SHELL_KWD_MAX_LENGTH] = {0};
	size_t shell_cmd1_pos = 0;

	char shell_cmd2[5191] = {0};
	size_t shell_cmd2_pos = 0;

	size_t i;
	size_t j;

	for (i = 0; i <= shell_cmd_length; ++i) {
		if (shell_cmd[i] == ' ' || i == shell_cmd_length) {
			if (shell_cmd1_pos != 0) {
				a = shell_lexical_analysis_is_kwd(shell_cmd1);
				if (a) {
					break;
				} else {
					printf("%s: command not found", shell_cmd1);
					return -1; // to edit
				}
			}
		} else {
			shell_cmd1[shell_cmd1_pos] = shell_cmd[i];
			shell_cmd1_pos += 1;
		}
	}

	for (j = i+1; j < shell_cmd_length; ++j) {
		shell_cmd2[shell_cmd2_pos] = shell_cmd[j];
		shell_cmd2_pos += 1;
	}
	size_t lgth1 = strlen(shell_cmd1);
	size_t lgth2 = strlen(shell_cmd2);

	// to avoid a lost of pointers in filesystem.c
	char* shell_cmd3 = malloc((lgth1+1) * sizeof(char));
	char* shell_cmd4 = malloc((lgth2+1) * sizeof(char));
	for (unsigned int i = 0; i < lgth1; ++i)
	{
		shell_cmd3[i] = shell_cmd1[i];
	}
	for (unsigned int i = 0; i < lgth2; ++i)
	{
		shell_cmd4[i] = shell_cmd2[i];
	}
	shell_cmd3[lgth1] = '\0';
	shell_cmd4[lgth2] = '\0';

	// printf("1:%s\n", shell_cmd1);
	// printf("2:%s\n", shell_cmd2);
	shell_lexical_analysis_dispatcher(shell_cmd3, shell_cmd4);
	return 0;
}

void shell_exec(char* shell_cmd, size_t shell_cmd_length) {
	shell_kwds_array_init();
	shell_kwds_array_append_misc();
	shell_kwds_array_append_filesystem();

	shell_lexical_analysis(shell_cmd, shell_cmd_length);

	printf("\nshell mode - disabled\n");
}
