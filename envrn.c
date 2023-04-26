#include "myshell.h"
/**
 * _myenv - prints the current env
 * @info: pt args and functions prototypes
 *
 * Return: Successful
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv -gets the value of an environment variabl
 * @n: env var name
 * @info: pt args and fns prototypes
 * Return: the value
 */
char *_getenv(info_t *info, const char *n)
{
	list_t *node = info->env;
	char *x;

	while (node)
	{
		x = starts_with(node->str, n);
		if (x && *x)
		{
			return (x);
		}
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - initilizw a new environment variable
 * @info: pt args and fccns prototypes
 *
 * Return: Always
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_puts("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
	{
		return (0);
	}
	return (1);
}
/**
 * _myunsetenv - Remove an environment variable
 * @info: pt args and fnct prototypes
 *
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_puts("Too few arguments. \n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
	{
		_unsetenv(info, info->argv[i]);
	}
	return (0);
}
/**
 * populate_env_list -populates env linked list
 * @info: pt args and fct prototypes
 *
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
	{
		add_node_end(&node, environ[i], 0);
	}
	info->env = node;
	return (0);
}
/* a NIYIBIZI Bonaventure codes */
