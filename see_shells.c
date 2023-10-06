#include "shell.h"

/**
 * inter_shell - function to run interactive shell
 * @kit: structure to be manipulated.
 * @av: main arguments.
 */

void inter_shell(rootkit *kit, char **av)
{
	size_t n;
	ssize_t num_bytes;
	int k;

	while (1)
	{
		n = 0;
		if (kit->n_free == 0)
		{
			free_struct(kit);
		}
		prompt_user();
		num_bytes = getline(&kit->buf, &n, stdin);
		if (num_bytes == -1 ||
				(_strlen(kit->buf) == 1 && kit->buf[0] == '\n'))
		{
			kit->sig = 1;
			kit->n_free = 1;
			continue;
		}
		else if (num_bytes > 0)
		{
			k = _strlen(kit->buf);
			if (kit->buf[k - 1] == '\n')
				kit->buf[k - 1] = '\0';
			kit->path = find_path();
			if (shell_loop(kit, av) == 0)
				continue;
		}
		else
			continue;
	}

}

/**
 * shell_loop - a function to execute the shell loop
 * @kit: structure for the manipualtion.
 * @av: main arguments.
 * Return: returns 0 on success
 */

int shell_loop(rootkit *kit, char **av)
{
	char **env;
	pid_t pd;
	int ch_status;
	char *temp;

	env = environ;
	kit->commands = parse_input(kit->buf);
	kit->paths = parse_input(kit->path);
	temp = find_command(kit->paths, kit->commands[0]);
	kit->commands[0] = temp;

	if (kit->commands[0] == NULL)
	{
		printf("\n%s: 1: %s: not found\n", av[0], strtok(kit->buf, " :\n\t"));
		if (kit->inter_shell == 1)
		{
			exit(127);
		}
		return (0);
	}

	pd = fork();
	if (pd == -1)
	{
		perror("Error");
	}
	if (pd == 0)
	{
		if (execve(kit->commands[0], kit->commands, env) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		wait(&ch_status);
	}
	return (0);
}
/**
 * prompt_user - a function to prompt the user.
 */

void prompt_user(void)
{
	printf("\n$  ");
}

/**
 * n_inter_shell - a function for the non-interactives
 * @kit: a structure for manipulation
 * @av:  main arguments.
 */

void n_inter_shell(rootkit *kit, char **av)
{
	size_t n;
	ssize_t num_bytes;
	char *temp;

	n = 0;

	while (1)
	{
		num_bytes = getline(&kit->buf, &n, stdin);

		if (num_bytes == -1)
		{
			break;
		}
		if (_strlen(kit->buf) == 1 && kit->buf[0] == '\n')
		{
			num_bytes = 0;
		}
		temp = strdup(kit->buf);
		if (strtok(temp, " :\n\t") == NULL)
		{
			num_bytes = 0;
		}
		if (num_bytes > 0)
		{
			kit->path = find_path();
			kit->inter_shell = 1;
			shell_loop(kit, av);
		}
	}
	free_struct(kit);
	exit(EXIT_SUCCESS);

}

