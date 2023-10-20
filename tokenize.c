#include "shell.h"

/**
 * sep - tokenizes the arguments of the commandline
 * @lines: pointer to the arguments
 * Return: an array to the tokenized strings
 */

char **sep(char *lines)
{
	char **arr, *token;
	size_t i = 0;

	arr = malloc(64 * sizeof(char *));
	if (arr == NULL)
	{
		perror("Unable to allocate space in memory for arr");
		exit(99);
	}

	token = strtok(lines, " \r\t");
	while (token)
	{
		arr[i++] = _strdup(token);
		token = strtok(NULL, " ");
	}
	arr[i] = NULL;
	return (arr);
}
