#include "shell.h"
/**
 * main - This is our entry point
 *
 * Return: 0 Always success
 */
int main(void)
{
	char command[100];

	while (1)/* True */
	{
		dis_prompt();
		read_command(command, sizeof(command));
		exec_command(command);
		env_to_path("path/bin");
	}
	return (0);
}
