#ifndef _KERNEL_SHELL
#define _KERNEL_SHELL

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>



#define SHELL_KWD_MAX_LENGTH 10
#define SHELL_KWDS_NMB 100

// 0 à 19 : 20 premières entrées = symboles "asbtraits"
// 20 à 63 : commandes

char shell_kwds[SHELL_KWD_MAX_LENGTH * SHELL_KWDS_NMB] = {0};

static int temp_shell_kwds_array_pos = 0;

void shell_kwds_array_init(void) {
	temp_shell_kwds_array_pos = 0;
	for (int i = 0; i < SHELL_KWD_MAX_LENGTH * SHELL_KWDS_NMB; ++i)
	{
		// printf("%c", shell_kwds[i]);
		shell_kwds[i] = 0x00;
	}
}


void shell_kwds_array_clean(void) {
	for (int i = 0; i < SHELL_KWD_MAX_LENGTH * SHELL_KWDS_NMB; ++i)
	{
		shell_kwds[i] = 0x00;
	}
}

static void shell_kwds_array_append(char* kwd) {
	int lgth = strlen(kwd);
	for (int i = 0; i < lgth; ++i)
	{
		shell_kwds[temp_shell_kwds_array_pos+i] = kwd[i];
	}
	temp_shell_kwds_array_pos += SHELL_KWD_MAX_LENGTH;
}


// temp_shell_kwds_array_pos = 
void shell_kwds_array_append_misc(void) {
	shell_kwds_array_append("alias");
	shell_kwds_array_append("basename");
	shell_kwds_array_append("cal");
	shell_kwds_array_append("date");
	shell_kwds_array_append("dirname");
	shell_kwds_array_append("echo");
	shell_kwds_array_append("expr");
	shell_kwds_array_append("false");
	shell_kwds_array_append("man");
	shell_kwds_array_append("printf");
	shell_kwds_array_append("read");
	shell_kwds_array_append("sleep");
	shell_kwds_array_append("tee");
	shell_kwds_array_append("time");
	shell_kwds_array_append("touch");
	shell_kwds_array_append("true");
}

void shell_kwds_array_append_filesystem(void) {
	shell_kwds_array_append("cat");
	shell_kwds_array_append("cd");
	shell_kwds_array_append("chown");
	shell_kwds_array_append("chmod");
	shell_kwds_array_append("cp");
	// shell_kwds_array_append("file");
	// shell_kwds_array_append("find");
	shell_kwds_array_append("ls");
	shell_kwds_array_append("mkdir");
	shell_kwds_array_append("mv");
	shell_kwds_array_append("pwd");
	shell_kwds_array_append("rm");
	shell_kwds_array_append("rmdir");
}

void shell_kwds_array_append_processes() {
	shell_kwds_array_append("at");
	shell_kwds_array_append("kill");
}


#endif
