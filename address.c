#include "myshell.h"
/**
 * bfree - frees a pointer and NULLS the address
 * @pt: address of the pointer to free
 *
 * Return: Always successful
 */
int bfree(void **pt)
{
	if (pt && *pt)
	{
		free(*pt);
		*pt = NULL;
		return (1);
	}
	return (0);
}
/* a NIYIBIZI Bonaventure codes */
