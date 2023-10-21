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

	vo msg;
	/*if (ac != 1)
	{
		write(STDOUT_FILENO, av[0], _strlen(av[0]));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, "0: ", 3);
		write(STDOUT_FILENO, msg, _strlen(msg));
		write(STDOUT_FILENO, av[1], _strlen(av[1]));
		write(STDOUT_FILENO, "\n", 2);
		exit(0);
	}*/
	if (ac == 2)
	{
		readline(av[0], av[1]);
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
	/*
	 * prompt = "";
	 *getlne(prompt, av[0], is_inter);
	 */
	return (0);
}

void readline(char *prog, char *file)
{
	int x = 0, code;
	char *filen = file;
	int file_descriptor = open(filen, O_RDONLY);
	ssize_t chars;
	char cmds[4096];
	vo chars;

	if (file_descriptor == -1)
	{
		fprintf(stderr, "%s: %d: Can't open %s\n", prog, x, filen);
		exit(EXIT_FAILURE);
	}

	chars = read(file_descriptor, cmds, sizeof(cmds));
	if (chars == 1)
	{
		fprintf(stderr, "%s: %d: No input in %s\n", prog, x, filen);
		exit(EXIT_FAILURE);
	}
	if (chars > 1)
	{
		code = file_run(cmds, x, prog, filen);
	}
	close(file_descriptor);
	exit(code);
}


int file_run(char *linebuff, int x, char *program, char *filen)
{
	char **faketok, **tokens;
	int j = 0;
	int built;

	faketok = file_sep(linebuff);
	while (faketok[j])
	{
		tokens = sep(faketok[j]);
		if (tokens[0] == NULL)
		{
			_free(tokens);
			continue;
		}
		if (_strcmp(tokens[0], "exit") == 0)
			free(linebuff), _free(faketok);
		built = inbuilts(tokens);
		if (built == 2)
		{
			fprintf(stderr, "%s: %d: %s: Illegal number: %s\n",
					program, x, tokens[0], tokens[1]);
			_free(tokens), exit(2);
		}
		if (built == -1)
		{
			fprintf(stderr, "%s: %d: %s: can't cd to %s\n"
					, program, x, tokens[0], tokens[1]);
			_free(tokens);
			continue;
		}
		if (built == 1)
		{
			fprintf(stderr, "%s: %d: Can't open %s\n"
					, program, x, filen);
			_free(tokens);
			exit(127);
		}
		if (built == NOT_INBUILT)
		{
			if (execute_bin(tokens) != 0)
			{
				if (errno == 1)
				{
					fprintf(stderr, "%s: %d: Can't open %s\n", program, x, filen);
					return (127);
				}
				errno = printerr(x, tokens[0], program);
			}
		}
		_free(tokens), free(faketok[j]), j++;
	} free(faketok);
	return (0);
}


char **file_sep(char *lines)
{
	char **arr, *token;
	size_t i = 0;

	arr = malloc(64 * sizeof(char *));
	if (arr == NULL)
	{
		perror("Unable to allocate space in memory for arr");
		exit(99);
	}

	token = strtok(lines, "\n");
	while (token)
	{
		arr[i++] = _strdup(token);
		token = strtok(NULL, "\n");
	}
	arr[i] = NULL;
	return (arr);
}
