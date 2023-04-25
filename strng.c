#include "myshell.h"
/**
 * _strlen - returns the length of the string
 * @h: is the string length to check
 * Return:interger size of the string
 */
int _strlen(char *h)
{
	int a = 0;

	if (!h)
		return (0);
	while (*h++)
		a++;
	return (a);
}
/**
 *_strcmp - Performs comparison of two strang
 *@g1: is the first strang
 *@g2: is the second strang
 *Return: success
 */
int _strcmp(char *g1, char *g2)
{
	while (*g1 && *g2)
	{
		if (*g1 != *g2)
			return (*g1 - *g2);
		g1++;
		g2++;
	}
	if (*g1 == *g2)
		return (0);
	else
		return (*g1 < *g2 ? -1 : 1);
}
/**
 * starts_with - chexks if needle stars with haystack
 * @needle: the subsring to find
 * @haystack:string to ne searchable
 * Return: 0 always success
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needlr++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - concatenates of two strings
 * @desbuf: is the destination of buffer
 * @srbuf: is the source f buffer
 * Return: 1 Always success
 */
char *_strcat(char *desbuf, char *srbuf)
{
	char *h = destbuf;

	while (*desbuf)
		desbuf++;
	while (*srbuf)
		*desbuf++ = *srbuf++;
	*debuf = *srbuf;
	return (h);
}
