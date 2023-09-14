#include "shell.h"
/**
 * niyo_play - this is my printf version,used to print output in my shell
 * @message: This is out put we display
 * @color: This is color for out put for the errors,and prompt
 * Return: no return
 */


void niyo_play(const char *message, const char *color)
{
	write(STDOUT_FILENO, message, strlen(message));
	write(STDOUT_FILENO, color, strlen(color));
	write(STDOUT_FILENO, "\033[0m", 5); /*5 lines to turn TO default color */
}
