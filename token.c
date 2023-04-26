#include "myshell.h"
/**
 * strtow -splits string into to words
 * @str: is the input string
 * @del: is the delimeter
 * Return: success
 */
char **strtow(char *str, char *del)
{
	int a, b, c, d, nwords = 0;
	char **h;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!del)
		del = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], del) && (is_delim(str[a + 1], del) || !str[a + 1]))
			nwords++;
	if (nwords == 0)
		return (NULL);
	h = malloc((1 + nwords) * sizeof(char *));
	if (!h)
		return (NULL);
	for (a = 0, b = 0; b < nwords; b++)
	{
		while (is_delim(str[a], del))
			a++;
		c = 0;
		while (!is_delim(str[a + c], del) && str[a + c])
			c++;
		h[b] = malloc((c + 1) * sizeof(char));
		if (!h[b])
		{
			for (c = 0; c < b; c++)
				free(h[c]);
			free(h);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			h[b][d] = str[a++];
		h[b][d] = 0;
	}
	h[b] = NULL;
	return (h);
}
/**
 * **strtow2 -  convert stringd into words
 * @str:is the input string
 * @del: is the delimeter
 * Return: NULL for faill
 */
char **strtow2(char *str, char del)
{
	int a, b, c, d, nwords = 0;
	char **h;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
	{
		if ((str[a] != del && str[a + 1] == del) ||
				(str[a] != del && !str[a + 1]) || str[a + 1] == del)
			nwords++;
	}
	if (nwords == 0)
		return (NULL);
	h = malloc((1 + nwords) * sizeof(char *));
	if (!h)
		return (NULL);
	for (a = 0, b = 0; b < nwords; b++)
	{
		while (str[a] == del && str[a] != del)
			a++;
		c = 0;
		while (str[a + c] != del && str[a + c] && str[a + c] != del)
			c++;
		h[b] = malloc((c + 1) * sizeof(char));
		if (!h[b])
		{
			for (c = 0; c < b; c++)
				free(h[c]);
			free(h);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			h[b][d] = str[a++];
		h[b][d] = 0;
	}
	h[b] = NULL;
	return (h);
}
/* a NIYIBIZI Bonaventure codes */
