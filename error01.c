#include "myshell.h"
/**
 * _erratoi -convers a string to an interger
 * @h: the atring to be converted
 * Return: -1 on error
 */
int _erratoi(char *h)
{
	int a = 0;
	unsigned long int result = 0;

	if (*h == '+')
		h++;
	for (a = 0; h[a] != '\0'; a++)
	{
		if (h[a] >= '0' && h[a] <= '9')
		{
			result *= 10;
			result += (h[a] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
/**
 * *print_error - print aan error message
 * @se: string that containing error
 * @info: this is parameter of struct
 * Return:-1 for error
 */
void print_error(info_t *info, char *se)
{
	_puts(info->fname);
	_puts(": ");
	print_d(info->line_count, STDERR_FILENO);
	_puts(": ");
	_puts(info->argv[0]);
	_puts(": ");
	_puts(se);
}
/**
 * print_dc -function prints a decimal (integer)
 * @input: is the input
 * @fd: is the filedestriptor
 * Return: number
 */
int print_dc(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int a, count = 0;
	unsigned int _abc_, current;

	if (fd == STDERR_FILENO)
		__putchar = _putchar;
	if (input < 0)
	{
		_abc_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abc_ = input;
	current = _abc_;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_abc_ / a)
		{
			__putchar('0' + current / a);
			count++;
		}
		current %= a;
	}
	__putchar('0' + current);
	count++;
	return (count);
}
/**
 * convert_number - converter fc,  and clone o9f itoa
 * @n: is the number
 * @base: base
 * @flags: argument flags
 * Return: tring
 */
char *convert_number(long int n, int base, int flags)
{
	static  char *arr;
	static char buffer[50];
	char sign = 0;
	char *pt;
	unsigned long y = n;

	if (!(flags & CONVERT_UNSIGNED) && n < 0)
	{
		y = -n;
		sign = '-';
	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pt = &buffer[49];
	*pt = '\0';

	do {
		*--pt = arr[y % base];
		y /= base;
	} while (y != 0);

	if (sign)
		*--pt = sign;
	return (pt);
}
/**
 * remove_comments - function replace first
 * @buffer: adreess of the string to modify
 * Return: Always 0;
 */
void remove_comments(char *buffer)
{
	int a;

	for (a = 0; buffer[a] != '\0'; a++)
		if (buffer[a] == '#' && (!a || buffer[a - 1] == ' '))
		{
			buffer[a] = '\0';
			break;
		}
}
/* a NIYIBIZI BOnaventur codes */
