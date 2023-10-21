#include "shell.h"

/**
 * execute_cmd - executes commands
 * @tokens: array of arguments
 * @path: full path to command
 */

void execute_cmd(char **tokens, char *path)
{
	size_t i = 0;
	int stat;
	pid_t child;
	vo i;

	errno = 0;
	child = fork();

	if (child == 0)
	{
		if (execve(path, tokens, environ) == -1)
		{
			perror(NULL);
		}
		exit(0);
	}
	if (child > 0)
	{
		wait(&stat);
		if (WIFEXITED(stat))
			errno = WEXITSTATUS(stat);
	}
	if (child < 0)
	{
		perror("execve");
		exit(1);
	}

}
