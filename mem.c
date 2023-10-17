#include "shell.h"

/**
 * *_memset - fills memory with a constant byte.
 * @s: pointer to put the constant
 * @n: max bytes to use
 */

void _memset(char **s, size_t n)
{

	if (n > 0)
	{
		size_t i;

		for (i = 0; i < n; i++)
		s[i] = NULL;
	}
}

/**
 * p_free -  a function to free a double pointer.
 * @ptr: pointer to an array of strings.
*/

void p_free(char **ptr)
{
	int i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = NULL;
			i++;
		}
		free(ptr);
		ptr = NULL;
	}

}

/**
 * t_free - a function to free a pair of pointers.
 *
 * @s: first pointer
 * @p: second pointer
 */

void t_free(char *s, char *p)
{
	free(s);
	free(p);
}

