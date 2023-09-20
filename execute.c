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
	extern char **environ;
	char **env = environ;

	if (strcmp(command, "env") == 0)
	{
		while (*env != NULL)
		{
			niyo_play("%s\n", *env);
			env++;
		}
		exit(EXIT_SUCCESS);
	}

	else if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

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
		execve(full_path, args, NULL);
		perror("Execution failed");
		niyo_play("./shell: No such file or directory", "\033[34m\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
