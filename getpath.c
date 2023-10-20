#include "shell.h"

/**
 * getpath - gets PATH
 * @path: command to check if it's in PATH
 * Return: full path to command
 */

char *getpath(char *path)
{
	char *pa;
	char fp[4086];
	char *token;
	char *fol;
	struct stat file;

	pa = _getenv("PATH");
	token = _strdup(pa);
	fol = strtok(token, "=");
	fol = strtok(NULL, ":");

	while (fol)
	{
		_strcpy(fp, fol);
		_strcat(fp, "/");
		_strcat(fp, path);
		if (stat(fp, &file) == 0)
		{
			free(token);
			/*path = fp;*/
			path = _strdup(fp);
			return (path);
		}

		fol = strtok(NULL, ":");
	}
	free(token);
	return (NULL);
}
