#include "shell.h"

/**
 * execute_bin - calls the execute_cmd function
 * @tokens: tokens
 * Return: 0 or -1
 */

int execute_bin(char **tokens)
{
	char *com = tokens[0];
	char *path;
	int i = 0;
	vo i;

	if (com[0] == '/' || com[0] == '.')
	{
		if (access(com, F_OK) != 0)
		{
			errno = 123;
			return (-1);
		}
		if (access(com, F_OK) != 0 || access(com, X_OK) != 0)
		{
			errno = 120;
			return (-1);
		}
		path = com;
	execute_cmd(tokens, path);
	}
	else
	{
		path = getpath(com);
		if (path == NULL)
		{
			errno = 123;
			return (-1);
		}
		execute_cmd(tokens, path);
		free(path);
	}
	return (0);
}
