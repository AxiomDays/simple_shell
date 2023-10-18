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
		_print("\n");
		exit(297);
	}
	return (inp);
}
