#include "myshell.h"
/**
 * _myexit - how to exit the shell
 * @info: this is for potential arguments and const functs protytyoes
 * Return: success to exit
 */
int _myexit(info_t *info)
{
	int exitchecker;

	if (info->argv[1])
	{
		exitchecker = _erratoi(info->argv[1]);
		if (exitchecker == -1)
		{
			info->status = 2;
			print_error(info, "Invalid Number ");
			_puts(info->argv[1]);
			_putchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd - changes the directory
 * @info: this is for potential arguments and const fuc prototypes
 * Return: success
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to");
		_puts(info->argv[1]), -putchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _myhelp - changing directory
 * @info: this is for potential args and funscs prototypes
 * Return: success
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("helps ,function not working\n");
	if (0)
	{
		_puts(*arg_array);
	}
	return (0);
}
/* a NIYIBIZI Bonaventure codes */
