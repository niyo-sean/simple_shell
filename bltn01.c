#include "myshell.h"
/**
 * _myhistory - displays the history
 * @info: tis is potential args and fnct prototypes
 * Return: succuss
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - sets alias tp string
 * @str: the string alias
 * @info: parameter struct
 * Return:Always success
 */
int unset_alias(info_t *info, char *str)
{
	char *x, y;
	int z;

	x = _strchar(str, '=');
	if (!x)
		return (1);
	y = *x;
	*x = 0;
	z = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*x = y;
	return (z);
}
/**
 * set_alias - sets alias
 * @str: the string alias
 * @info: parameter struct
 * Return: always 0
 */
int set_alias(info_t *info, char *str)
{
	char *x;

	x = _strchar(str, '=');
	if (!x)
		return (1);
	if (!*++x)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - prints an alias
 * @node: the alias node
 *
 * Return: Always 0
 */
int print_alias(list_t *node)
{
	char *x = NULL, *a = NULL;

	if (node)
	{
		x = _strchar(node->str, '=');
		for (a = node->str; a <= x; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(x + 1);
		puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - mimics the alias builtin
 * @info: petential args and functs prototypes
 *
 * Return: always
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *x = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		x = _strchar(info->argv[i], '=');
		if (x)
		{
			set_alias(info, info->argv[i]);
		}
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}
	return (0);
}
/* a NIYIBIZI BOnaventure codes */
