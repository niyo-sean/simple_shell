#include "myshell.h"
/**
 * _puts - prints an inputs stringsfrom keyboard
 * @strg: the string being printed
 *
 * Return: void
 */
void _puts(char *strg)
{
	int a = 0;

	if (!strg)
		return;
	while (strg[a] != '\0')
	{
		_putchar(strg[a]);
		a++;
	}
}
/**
 *_putchar - writes the character c to sterr
 * @h: this the character to be printed
 * Return: 1 on success
 */
int _putchar(char h)
{
	static int a;
	static char buffer[WRITE_BUFFER_SIZE];

	if (h == BUFFER_FLUSH || a >=  WRITE_BUFFER_SIZE)
	{
		write(2, buffer, a);
		a = 0;
	}
	if (h != BUFFER_FLUSH)
		buffer[a++] = h;
	return (1);
}
/**
 * _putfd - writes the character h to gives fd
 * @fd: the filedescription to write
 * @h: is the character being to be printed
 * Return: 1 on successful
 */
int _putfd(char h, int fd)
{
	static int a;
	static char buffer[WRITE_BUFFER_SIZE];

	if (h == BUFFER_FLUSH || a >= WRITE_BUFFER_SIZE)
	{
		write(fd, buffer, a);
		a = 0;
	}
	if (h != BUFFER_FLUSH)
		buffer[a++] = h;
	return (1);
}
/**
 * _putsfd - prints an inputs of string from keyboard
 * @fd: the filedescription
 * @strg: is the string to be printed
 *
 * Return: 1
 */
int _putsfd(char *strg, int fd)
{
	int a = 0;

	if (!strg)
		return (0);
	while (*strg)
	{
		a += _putfd(*strg++, fd);
	}
	return (a);
}
/* a NIYIBIZI Bonaventure codes */
