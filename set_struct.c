#include "shell.h"

/**
 * free_struct - a function to free the structure
 * @kit: structure to be freed
 */

void free_struct(rootkit *kit)
{
	int i;

	if (kit)
	{
		if (kit->commands)
		{

			for (i = 0; kit->commands[i] != NULL; i++)
			{
				if (kit->commands[i])
				{
					free(kit->commands[i]);
				}
			}
			free(kit->commands);
		}
		if (kit->paths)
		{

			for (i = 0; kit->paths[i] != NULL; i++)
			{
				if (kit->paths[i])
				{
					free(kit->paths[i]);
				}
			}
			free(kit->paths);
		}
		if (kit->path)
		{
			free(kit->path);
		}
		if (kit->buf)
		{
			free(kit->buf);
		}
	}
}

/**
 * init_struct - a function to intialize the structure.
 * @kit: pointer to the structure
 */

void init_struct(rootkit *kit)
{
	if (kit)
	{
		kit->commands =  NULL;
		kit->buf = NULL;
		kit->paths = NULL;
		kit->path = NULL;
		kit->sig = 0;
		kit->inter_shell = 0;
		kit->n_free = 0;
	}
}

