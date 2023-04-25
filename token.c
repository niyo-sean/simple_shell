Rrnclude "myshell.h"
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
		if (!is_delim(str[a], del) && (is_delim(str[a +1], del) || !str[a + 1]))
			nwords++;
	if (nwords == 0)
		return (NULL);
	h = malloc
