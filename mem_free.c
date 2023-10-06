#include "shell.h"

/**
 * free_mem - a function to free memory in heap
 * @ptr: pointer to the memory location
 */

void free_mem(char *ptr)
{
	if (ptr)
	{
		free(ptr);
	}
}

/**
 * free_dmem - a function free memory from **ptr
 * @ptr: pointer to the memory location
 */

void free_dmem(char **ptr)
{
	int i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
	free(ptr);
	}
}

/**
 * cleanup - a function to be called upon exit
 *
 */

void cleanup(void)
{
	fflush(stdin);
	fflush(stdout);
}


