#include "shell.h"

/**
 * find_path - a function to find the path string in env[]
 *
 * Return: null or pointer to the path string.
 */

char *find_path()
{
	char **env;
	char *path_string, *temp;
	int i, j;

	env = (environ);
	for (i = 0; env[i] != NULL; i++)
	{
		j = 0;
		if (env[i][j] == 'P' &&
			env[i][j + 1] == 'A' &&
			env[i][j + 2] == 'T' &&
			env[i][j + 3] == 'H')
		{
			temp = _strdup(env[i]);
			strtok(temp, "=");
			path_string = _strdup(strtok(NULL, "="));
			break;
		}
	}
	free(temp);

	return (path_string);
}
