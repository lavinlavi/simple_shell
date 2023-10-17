#include "shell.h"
/**
 * execution - a function to fork and spawn a shell
 * @argv: the commands to be executed.
*/

void execution(char **argv)
{
	pid_t pd;
	int ch_status;
	char **env;

	env = environ;
	pd = fork();

	if (pd == -1)
	{
		perror("\nError:");
		exit(EXIT_FAILURE);
	}
	if (pd == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("\nError:");
			p_free(argv);
		}
	}
	if (pd > 0)
	{
		wait(&ch_status);
	}
}
