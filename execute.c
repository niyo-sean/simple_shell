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
	char full_path[250];
	char *my_path = getenv("MY_PATH");
	char *input = strdup(command);
	char *token = strtok(input, " ");

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
		if (my_path == NULL)
		{
			perror("MY_PATH env variable not  set.\n");
			exit(EXIT_FAILURE);
		}
		snprintf(full_path, sizeof(full_path), "%s/%s", my_path, args[0]);
		if (access(full_path, X_OK) != 0)
		{
			perror("Error accesssing or executing");
			exit(EXIT_FAILURE);
		}
		/* execute command and its arguments */
		execve(full_path, args, NULL);
		perror("Execution failed");
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
