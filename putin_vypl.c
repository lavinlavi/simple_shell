#include "shell.h"


/**
 * find_command - a function to find the right dir.
 * @temp_com: pointer to strings of directories.
 * @temp_path: the first input of the user.
 *
 * Return: returns a pointer to a string
 * Null otherwise.
 */

char *find_command(char **temp_path, char *temp_com)
{
	struct stat statbuf;
	char *temp, *c_string, *o_command;
	int i;
	char **path;

	o_command = strdup(temp_com);
	path = temp_path;
	if (stat(o_command, &statbuf) == 0)
	{
		if (access(o_command, F_OK | X_OK) == 0)
		{
			c_string = o_command;
			return (c_string);
		}
	}

	for (i = 0; path[i] != NULL; i++)
	{
		temp = str_maker(path[i], o_command);
		if (stat(temp, &statbuf) == 0)
		{
			if (access(temp, F_OK | X_OK) == 0)
			{
				c_string = temp;
				return (c_string);
			}
			if (access(temp, F_OK | X_OK) == -1)
			{
				return (NULL);
			}
		}
		free(temp);
	}
	free(o_command);
	return (NULL);
}


