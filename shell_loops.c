#include "myshell.h"
/**
 * hsh - main shell loops
 * @info: the parameter of struct
 * @v: the argument vector from main()
 * Return: Always success
 */
int hsh(info_t *info, char **v)
{
	ssize_t x = 0;
	int builtin_ret = 0;

	while (x != -1 && builtin_ret != -2)
	{
		/*clear_info(info);*/
		if (interactive(info))
			_puts("$ ");
		_putchar(BUFFER_FLUSH);
		x = get_input(info);
		if (x != -1)
		{
			set_info(info, v);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}
/**
 * find_builtin -finds a builtin commands for shell
 * @info: the paramater struct
 * Return: Always 0 success
 */
int find_builtin(info_t *info)
{
	int a, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhstry},
		{"setenv", _mysetenv},
		{"unsetenv", _mysetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (a = 0; builtintbl[a].type; a++)
		if (_strcmp(info->argv[0], builtintbl[a].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[a].func(info);
			break;
		}
	return (built_in_ret);
}
/**
 * find_cmd - finds a command in path of shell
 * @info: the parameter of struct
 *
 * Return: nothing
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int a, d;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (a = 0, d = 0; info->arg[a]; a++)
		if (!is_delim(info->arg[a], "\t\n"))
			d++;
	if (!d)
		return;
	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}
/**
 * fork_cmd - we need fork here for child and parent process
 * @info: the sstruct parameter
 *
 * Return:void
 */
void fork_cmd(info_t *info)
{
	pid_t chld;

	chld = fork();
	if (chld == -1)
	{
		perror("error:");
		return;
	}
	if (chld == 0)
	{
		if (execve(info->path, info->argv, get_envirin(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "permission Denied \n");
		}
	}
}
/* a NIYIBIZI Bonaventure codes */
