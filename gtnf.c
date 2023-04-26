#include "myshell.h"
/**
 * clear_info - to initializes info struct
 * @info: is the parameter of struct ad
 * Return: np return
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->argc = 0;
	info->path = NULL;
}
/**
 * set_info - initializes to parameter of instruct
 * @x: use thisd argument vector
 * @info: parameter of argument vector
 * Return: no return
 */
void set_info(info_t *info, char **x)
{
	int a = 0;

	info->fname = x[0];

	if (info->arg)
	{
		info->argv = strtow(info->arg, "\t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (a = 0; info->argv && info->argv[a]; a++)
			;
		info->argc = a;
		replace_alias(info);
		replace_vars(info);
	}
}
/**
 * free_info - freea parameter of struct
 * @y: is true for all struct fields
 * @info: parameter of struct
 * Return: no return
 */
void free_info(info_t *info, int y)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (y)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUFFER_FLUSH);
	}
}
/* a NIYIBIZI Boanaventure codes */
