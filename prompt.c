#include "main.h"
/**
 * *prompt - Entry point
 *
 * Description: 'collects user input and returns'
 * Return: Void
 */
char *prompt(void)
{
	char *inp;
	ssize_t text;
	size_t bufsize = 32;

	inp = NULL;
	if (isatty(STDIN_FILENO) == 1)
		_print("$ ");
	text = getline(&inp, &bufsize, stdin);

	if (text == -1)
	{
		free(inp);
		exit(297);
	}
	if (inp[0] == '\n')
	{
		free(inp);
		continue;
	}
	return (inp);
}

char *non_inter_prompt(void)
{
	char *inp;
	ssize_t text;
	size_t bufsize = 32;

	inp = NULL;
	text = getline(&inp, &bufsize, stdin);

	if (text == -1)
	{
		free(inp);
		exit(297);
	}
	return (inp);
}
