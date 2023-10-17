#include "shell.h"


/**
 * main - the main function
 * @av: argument vector
 * @ac: argument count.
 *
 * Return: returns 0 on succes.
 */

int main(int ac, char **av)
{
	signal(SIGINT, SIG_DFL);
	if (ac > 1)
	{
		return (0);
	}
	if (ac == 1)
	{
		if (isatty(STDIN_FILENO))
		{
			inter_shell(av);
		}
		if (!isatty(STDIN_FILENO))
		{
			n_inter_shell(av);
		}
	}


	return (0);
}

