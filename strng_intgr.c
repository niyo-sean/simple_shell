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
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result+= (s[i] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
/* a NIYIBIZI Bonaventur codes */
