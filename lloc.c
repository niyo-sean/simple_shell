#include "myshell.h"
/**
 **_memset - file memory with a const bytes
 * @x: the amount of bytes ti be fulled
 * @y: the pointer
 * @z: the bytes to fill *y
 * Return: success
 */
char *_memset(char *y, char z, unsigned int x)
{
	unsigned int m;

	for (m = 0; m < x; m++)
		y[m] = z;
	return (y);
}
/**
 * ffree - free the string to string
 * @h: string to strings
 * Return: no return
 */
void ffree(char **h)
{
	char **n = h;

	if (!h)
		return;
	while (*h)
		free(*h++);
	free(n);
}
/**
 * _realloc - blocking of memory
 * @p:previous pointer
 * @new_size: byte of new block
 * @old_size: byte of previous block
 * Return: Succuss
 */
void *_realloc(void *p, unsigned int new_size, unsigned int old_size)
{
	char *ptr;

	if (!p)
		return (malloc(new_size));
	if (!new_size)
		return (free(p), NULL);
	if (new_size == old_size)
		return (p);
	ptr = malloc(new_size);
	if (!ptr)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		ptr[old_size] = ((char *)p)[old_size];
	free(p);
	return (ptr);
}
/* a NIYIBIZI Bonaventure codes */
