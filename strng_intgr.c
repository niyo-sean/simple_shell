#include "myshell.h"
/* this functions will convert strings into intergers*/
/**
 * interactive - shell int interactive mode
 * @info : is the struct address
 *
 * Return: always successful
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - this is for delimeter of characters
 * @c : is the char checking for delim
 * @delim : string delimeter
 * Return: Alwys success
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
		{
			return (1);
		}
	return (0);
}
/**
 * _isalpha - this is for alphabetics
 * @c : input for character
 * Return: success
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * _atoi - converts a stings to an integers
 * @b : is the stings to be converted
 * Return: success
 */
int _atoi(char *b)
{
	int i, x = 1, y = 0. output;
	unsigned int z = 0;

	for (i = 0; b[i] != '\0' && y != 2; i++)
	{
		if (b[i] == '-')
			x *= -1;
		if (b[i] >= '0' && b[i] <= '9')
		{
			y = 1;
			z *= 10;
			z += (b[i] - '0');
		}
		else if (y == 1)
		{
			y = 2;
		}
	}
	if (x == -1)
		output = -z;
	else
		output = z;
	return (z);
}
/* a NIYIBIZI Bonaventur codes */
