#include "shell.h"

/**
 * parse_command - a function to parse the commands
 *  entered
 * @buf: the input of the user.
 * @command: the command searched in the file structure
 * Return: returns a pointer to an array of strings
*/

char **parse_command(char *buf, char *command)
{
	size_t token_size;
	char **argv;
	char *temp;
	int c_siz, j;
	char *input;

	input = _strdup(buf);
	token_size = get_token_size(input);
	argv = malloc(sizeof(char *) * (token_size  + 1));
	_memset(argv, (token_size + 1));

	if (!argv)
	{
		free(input);
		perror("\nError:");
		exit(EXIT_FAILURE);
	}
	c_siz = _strlen(command);
	argv[0] = malloc(sizeof(char) * (c_siz + 1));
	_strcpy(argv[0], command);
	temp = strtok(input, " \n\t");

	for (j = 1; temp; j++)
	{
		temp = strtok(NULL, " \n\t");
		if (temp == NULL)
		{
			break;
		}
		argv[j] = malloc(sizeof(char) * (_strlen(temp) + 1));
		_strcpy(argv[j], temp);
	}
	free(input);

	return (argv);
}

/**
 * get_token_size - a function to determine the token size
 * @buf: pointer to a buffer
 *
 * Return: returns the token size
 */
size_t get_token_size(char *buf)
{
	size_t token_size;
	char *temp, *token;

	token_size = 0;
	temp = _strdup(buf);
	token = strtok(temp, " :\n\t");

	while (token)
	{
		token_size++;
		token = strtok(NULL, " :\n\t");
	}
	free(temp);
	return (token_size);
}

/**
 * get_command - attempt to find the right command
 * @path: the path environment variable.
 * @buf: the commands entered by the user.
 *
 * Return: On success pointer to the complete command
 * Else return NULL
*/

char *get_command(char *path, char *buf)
{
	struct stat statbuf;
	char *f_input, *temp, *token;
	char *input;

	input = _strdup(buf);
	f_input = _strdup(strtok(input, " \n\t"));
	if (stat(f_input, &statbuf) == 0)
	{
		if (access(f_input, F_OK | X_OK) == 0)
		{
			free(input);
			return (f_input);
		}
	}
	free(f_input);
	token = strtok(path, " :\n\t");
	temp = NULL;
	while (token)
	{
		temp = str_maker(token, input);
		if (stat(temp, &statbuf) == 0)
		{
			if (access(temp, F_OK | X_OK) == 0)
			{
				free(input);
				return (temp);
			}
		}
		token = strtok(NULL, " :\n\t");
		free(temp);
		temp = NULL;
	}
	free(input);

	return (NULL);
}
