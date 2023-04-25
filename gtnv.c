#include "myshell.h"
/**
 * get_environ - returns the string array copy for the environ
 * @info: pt args and const fcn prototype
 * Return: Always succuss
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		fo->env_changed = 0;
	}
	return (info->environ);
}
/**
 * _unsetenv - REmove an anv variable
 * @info: strcture pt aargs and cons
 * @y: is the string env
 * Return: 1
 */
int _unsetenv(info_t *info, char *y)
{
	list_t *node = info->env;
	size_t a = 0;
	char *c;

	if (!node || !y)
		return (0);
	while (node)
	{
		c = starts_with(node->str, y);
		if (c && *c == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), a);
			a = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		a++;
	}
	return (info->env_changed);
}
/**
 * _setenv - initializee a new environment var
 * @y: is the string enbv var property
 * @info: is the pt aeg and const of fnct prototype
 * @z: is the string env var value
 * Return: succesful
 */
int _setenv(info_t *info, char *y, char *z)
{
	char *buff = NULL;
	list_t *node;
	char *c;

	if (!y || !z)
		return (0);
	buffer = malloc(_strlen(y) + _strlen(z) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, y);
	_strcat(buffer, "=");
	_strcat(buffer, z);
	node = info->env;
	while (node)
	{
		c = strats_with(node->str, y);
		if (c && *c == '=')
		{
			free(node->str);
			node->str = buffer;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env). buffer, 0);
	free(buffer);
	info->env_changed = 1;
	return (0);
}
/* a NIYIBIZI Bonaventur codes */
