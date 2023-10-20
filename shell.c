#include "shell.h"

/**
 * main - a simple shell
 * @ac: argument number
 * @av: argument vectors
 * Return: 0
 */


int main(int __attribute__ ((unused)) ac, char **av)
{
	char *prompt = "";
	char *msg = "Can't open ";
	size_t is_inter = 1;

	if (ac != 1)
	{
		write(STDOUT_FILENO, av[0], _strlen(av[0]));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, "0: ", 3);
		write(STDOUT_FILENO, msg, _strlen(msg));
		write(STDOUT_FILENO, av[1], _strlen(av[1]));
		write(STDOUT_FILENO, "\n", 2);
		exit(0);
	}
	if (isatty(STDIN_FILENO))
	{
		is_inter = 1;
		prompt = "($) ";
		getlne(prompt, av[0], is_inter);
	}
	else
	{
		non_getlne(av[0]);
	}
	/*prompt = "";
	getlne(prompt, av[0], is_inter);*/
	return (0);
}
