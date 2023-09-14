#include "shell.h"
/**
 * dis_prompt - This is our prompt function
 *
 * Return: no return
 */
void dis_prompt(void)
{
	char *dir_color = "\033[34m"; /* Green color */
	char *prompt_txt_color = "\033[32m"; /* Blue color */

	/* Write green color to  Dir */
	write(STDOUT_FILENO, dir_color, strlen(dir_color));
	/*write blue color to prompt text */
	write(STDOUT_FILENO, prompt_txt_color, strlen(prompt_txt_color));
	niyo_play("niyo_sean_shell$", prompt_txt_color);
	niyo_play(" ", dir_color);
}
