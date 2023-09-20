#include "shell.h"

/**
 * exec_command - This is our shell execution
 * @command: This is user input must being executable
 */
void exec_command(const char *command)
{
	pid_t child_pid = fork();
	char *args[150];
	int arg_count = 0;
	char *token = strtok((char *)command, " ");

	if (child_pid == -1)
	{
		niyo_play("Error forking process", "\033[34m\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		/* execute command and its arguments */
		execve(args[0], args, NULL);
		/* If execute command fails */
		niyo_play("./shell: No such file or directory", "\033[34m\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}

/**
 * end_of_file - This is EOF function handling
 *
 * Return: 0 on success
 */
int end_of_file(void)
{
	char input[256];

	while (1)/*True*/
	{
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		if (input[strlen(input) - 1] == '\n')
		{
			input[strlen(input) - 1] = '\0';
		}
		exec_command(input);
	}
	return (0);
}
/*Done by niyo-sean */
