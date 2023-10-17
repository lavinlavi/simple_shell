#include "shell.h"

/**
 * inter_shell - function to run interactive shell
 * @av: main arguments.
 */

void inter_shell(char **av)
{
	char *buf, *input, *path, **argv, *command;
	ssize_t num_bytes;
	size_t n;
	int sig;

	while (1)
	{
		sig = n = 0;
		input = NULL;
		prompt_user();
		num_bytes = getline(&input, &n, stdin);
		if (num_bytes == -1 ||
				(num_bytes == 1 && input[num_bytes - 1] == '\n'))
			continue;
		else if (num_bytes > 0)
		{
			if (input[num_bytes - 1] == '\n')
				input[num_bytes - 1] = '\0';
			buf = malloc(sizeof(char) * num_bytes);
			if (!buf)
			{
				perror("\nError:");
				break;
			}
			strcpy(buf, input);
			path = find_path();
			command = get_command(path, buf);
			t_free(input, path);
			if (!command)
			{
				printf("\n%s: 1: %s: not found\n", av[0], strtok(buf, " :\n\t"));
				free(buf);
				sig++;
			}
			else if (command != NULL && sig == 0)
			{
				argv = parse_command(buf, command);
				if (argv != NULL)
					execution(argv);
				p_free(argv);
				t_free(buf, command);
				command = buf = path = NULL;
			}
			else
			{
				free(buf);
				continue;
			}
		}
	}
}

/**
 * prompt_user - a function to prompt the user.
 */

void prompt_user(void)
{
	char *pr;

	pr = "\n$ ";
	write(1, pr, 3);
}


/**
 * n_inter_shell - a function for the non-interactives
 * @av:  main arguments.
 */

void n_inter_shell(char **av)
{
	size_t n;
	ssize_t num_bytes;
	char *buf, *input, *path, **argv, *command;

	n = 0;
	while (1)
	{
		input = NULL;
		num_bytes = getline(&input, &n, stdin);
		if (num_bytes == -1)
			break;
		if (num_bytes == 1 && input[0] == '\n')
			num_bytes = 0;
		else if (num_bytes > 0)
		{
			if (input[num_bytes - 1] == '\n')
			{
				input[num_bytes - 1] = '\0';
			}
			buf = malloc(sizeof(char) * num_bytes);
			if (!buf)
			{
				perror("\nError:");
				break;
			}
			strcpy(buf, input);
			path = find_path();
			command = get_command(path, buf);
			t_free(path, input);
			if (!command)
			{
				printf("\n%s: 1: %s: not found\n", av[0], strtok(buf, " :\n\t"));
				free(buf);
			}
			else if (command != NULL)
			{
				argv = parse_command(buf, command);
				if (argv != NULL)
				{
					execution(argv);
				}
				p_free(argv);
				t_free(command, buf);
				command = buf = path = NULL;
			}
			else
			{
				free(buf);
				continue;
			}
		}
	}
}
