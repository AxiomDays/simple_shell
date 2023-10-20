#include "shell.h"


/**
 * __exit - exits a process
 * @tokens: tokens of commands
 * Return: status
 */

int __exit(char **tokens)
{
	if (tokens[1] != NULL)
		errno = _atoi(tokens[1]);
	else if (tokens[1] == NULL && errno == 0)
		errno = 0;
	_free(tokens);
	exit(errno);
}


/**
 * inbuilts - Inbuilt functions
 * @tokens: tokens of commands
 * Return: return macros if is a builtin or 0
 */

int inbuilts(char **tokens)
{
	size_t i;

	inbuilt_t fun[] = {
		{"exit", __exit},
		{"env", _env},
		{NULL, NULL}
	};

	for (i = 0; fun[i].name; i++)
	{
		if (strcmp(fun[i].name, tokens[0]) == 0)
		{
			return (fun[i].func(tokens));
		}
	}
	/*_free(tokens);*/
	return (NOT_INBUILT);
}


/**
 * _env - prints environment variables
 * @tokens: tokens of commands
 * Return: 0
 */

int _env(char **tokens)
{
	size_t i = 0;
	char *ptr;
	vo tokens;

	while (environ[i])
	{
		ptr = environ[i++];
		write(STDOUT_FILENO, ptr, _strlen(ptr));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
