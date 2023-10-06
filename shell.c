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
	rootkit my_structure;

	rootkit *kit = &my_structure;
	atexit(cleanup);
	init_struct(kit);
	if (ac > 1)
	{
		exit(EXIT_FAILURE);
	}
	if (ac == 1)
	{
		if (isatty(STDIN_FILENO))
		{
			inter_shell(kit, av);
		}
		if (!isatty(STDIN_FILENO))
		{
			n_inter_shell(kit, av);
		}
	}


	return (0);
}


