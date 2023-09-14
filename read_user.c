#include "shell.h"
/**
 * read_command - This function is user input command
 * @command: This is user input commands
 * @size: This is size of input
 */
void read_command(char *command, size_t size)
{

	if (fgets(command, size, stdin) == NULL)
	{

		if (feof(stdin))
		{
			niyo_play("\033[32m", "\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			niyo_play("Invalid command.", "\033[31m\n");
			exit(EXIT_FAILURE);
		}
	}
	/*line of codes  to remove new line */
	command[strcspn(command, "\n")] = '\0';
}

