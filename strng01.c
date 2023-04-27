#include "myshell.h"
/**
 * _strcpy - this is going to copy a string
 * @desbuf: is the distinaion of buffer
 * @srbuf: is the source of buffer
 * Return: address of dest
 */
char *_strcpy(char *desbuf, char *srbuf)
{
	int a = 0;

	if (desbuf == srbuf || srbuf == 0)
		return (desbuf);
	while (srbuf[a])
	{
		desbuf[a] = srbuf[a];
		a++;
	}
	desbuf[a] = 0;
	return (desbuf);
}
/**
 * _strdup - Is the duplication of string
 * @str:is the string duplicate
 *Return: adress to the dup of str
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--str;
	return (ret);
}
/**
 * _puts - prints an inputs from keyboard
 * @str: the string printed
 * Return: void
 */
void _puts(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}
}
/**
 * _putchar - writr the character to stdout
 *  @h: the char to print
 *  Return: 1 success
 */
int _putchar(char h)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (h == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (h != BUF_FLUSH)
		buf[a++] = h;
	return (1);
}
/* a NIYIBIZI Bonaventure codes */
