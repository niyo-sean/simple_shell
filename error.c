#include "myshell.h"
/**
 * _eputs - prints an inputs stringsfrom keyboard
 * @str: the string being printed
 *
 * Return: void
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}
/**
 *_eputchar - writes the character c to sterr
 * @c: this the character to be printed
 * Return: 1 on success
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >=  WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * _putfd - writes the character h to gives fd
 * @fd: the filedescription to write
 * @c: is the character being to be printed
 * Return: 1 on successful
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * _putsfd - prints an inputs of string from keyboard
 * @fd: the filedescription
 * @str: is the string to be printed
 *
 * Return: 1
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
/* a NIYIBIZI Bonaventure codes */
