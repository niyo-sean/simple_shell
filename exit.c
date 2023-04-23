#include "myshell.h"
/**
 * _strncpy - copies a string
 * @dest: string destination
 * @src: string source
 * @w: amount of characters copied
 * Return: Always success
 */
char *_strncpy(char *dest, char *src, int w)
{
	int i, m;
	char *z = dest;

	i = 0;
	while (src[i] != '\0' && i < w - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < w)
	{
		m = 1;
		while (m < n)
		{
			dest[m] = '\0';
			m++;
		}
	}
	return (z);
}
/**
 * _strncat - concatenatse
 * @dest: first string
 * @src : second string
 * @w: the amount of bytes
 * Return: success
 */
char *_strncat(char *dest, char *src, int w)
{
	int i, m;
	char *z = dest;

	i - 0;
	m = 0;
	while (dest[i] != '\0')
		i++;
	while (src[m] != '\0' && m < n)
	{
		dest[i] = src[m];
		i++;
		m++;
	}
	if (m < n)
		dest[i] = '\0';
	return (z);
}
/**
 * _strchr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 * Return: succefful
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			return (s);
		}
	} while (*s++ != '\0');
	return (NULL);
}
/* a NIYIBIZI Bonaventure codes */
