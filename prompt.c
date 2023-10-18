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
	printf("$ ");
	text = getline(&inp, &bufsize, stdin);

	if (text == -1)
	{
		free(inp);
		exit(297);
	}
	return (inp);
}
