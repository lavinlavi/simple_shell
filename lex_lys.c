#include "shell.h"


/**
 * parse_input - a function to parse user input;
 * @struct_buf: a pointer to the string
 *
 * Return: returns a pointer to a pointer or NULL
 */

char **parse_input(char *struct_buf)
{

	size_t token_size;
	int i;
	char **argv, *token;
	char *temp;
	char *buf;

	buf = strdup(struct_buf);
	if (!buf)
	{
		return (NULL);
	}
	temp = strdup(struct_buf);
	token_size = get_token_size(buf);

	if (token_size == 0)
	{
		return (NULL);
	}
	i = 0;
	token_size++;
	argv = malloc(sizeof(char *) * token_size);
	if (!argv)
	{
		return (NULL);
	}
	token = strtok(temp, " :\n\t");
	while (token)
	{
		argv[i] = token;
		if (argv[i] == NULL)
		{
			return (NULL);
		}
		i++;
		token = strtok(NULL, " :\n\t");
	}
	argv[i] = NULL;
	free(buf);
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
	temp = strdup(buf);
	token = strtok(temp, " :\n\t");

	while (token)
	{
		token_size++;
		token = strtok(NULL, " :\n\t");
	}
	free(temp);
	return (token_size);
}

