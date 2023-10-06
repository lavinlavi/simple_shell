#include "shell.h"


/**
 * find_path - a function to find the path string in env[]
 *
 * Return: null or pointer to the path string.
 */

char *find_path()
{
	char **env;
	char delim = '=';
	int i, j;
	char *path_string;
	size_t env_siz;
	char **argv;

	env = environ;
	env_siz = 0;
	for (j = 0; env[j] != NULL; j++)
		env_siz++;
	path_string = NULL;
	argv = malloc(sizeof(char *) * (env_siz + 1));
	if (!argv)
		return (NULL);
	argv[env_siz] = NULL;
	for (i = 0; env[i] != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(env[i]) + 1));
		_memset(argv[i], 0, _strlen(env[i]) + 1);
		if (!argv[i])
		{
			return (NULL);
		}
		strcpy(argv[i], env[i]);
	}
	for (i = 0; argv[i] != NULL; i++)
	{
		j = 0;
		if (argv[i][j] == 'P' &&
			argv[i][j + 1] == 'A' &&
			argv[i][j + 2] == 'T' &&
			argv[i][j + 3] == 'H')
		{
			strtok(argv[i], &delim);
			path_string = strdup(strtok(NULL, &delim));
		}
	}
	free_dmem(argv);
	return (path_string);
}



