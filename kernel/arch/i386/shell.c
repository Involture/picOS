void shell_exec(char* shell_cmd, unsigned char shell_cmd_length) {
	if (shell_cmd[0] == 'e' && shell_cmd[1] == 'c' && shell_cmd[2] == 'h' && shell_cmd[3] == 'o') {
		for (int i = 0; i < shell_cmd_length; ++i)
		{
			printf("%c", shell_cmd[i+5]);
		}
	}
	printf("\nshell mode - disabled\n");
}
