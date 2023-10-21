#include "shell.h"
/**
 * set_env - sets or edit an environment variable
 * @var: key
 * @val: value
 * Return: 0 if successful, if not, -1
 */
int set_env(char *key, char *value)
{
	int x = 0, length;
	char *ptr;

	if (key == NULL || value == NULL)
	{
		perror("Invalid argument for set_env");
		return (0);
	}

	ptr = malloc(_strlen(key) + _strlen(value) + 2);

	if (ptr == NULL)
	{
		perror("Malloc error");
		exit(EXIT_FAILURE);
	}

	length = _strlen(key);

	strcpy(ptr, key);
	strcpy(ptr, "=");
	strcpy(ptr, value);

	while (environ[x])
	{
		if (_strncmp(environ[x], key, length) == 0 && environ[x][length] == '=')
			{
				free(environ[x]);
				environ[x] = ptr;
				return (0);
			}
		x++;
	}
	free(environ[x]);
	environ[x] = ptr;
	environ[x + 1] = NULL;
	return (0);
}

int unset_env(char *key)
{
	int located = 0, x = 0, length = 0;
	char *ptr;

	if (key == NULL)
	{
		perror("Invalid argument to unset_env");
		return (0);
	}

	ptr = _getenv(key);

	if (ptr == NULL)
	{
		perror("Variable not found");
		return (0);
	}

	length = _strlen(key);

	while (environ[x])
	{
		if (!located)
		{
			if (_strncmp(environ[x], key, length) == 0 && environ[x][length] == '=')
			{
				located = 1;
				free(environ[x]);
			}
			continue;
		}
		environ[x - 1] = environ[x];
	}
	environ[x - 1] = environ[x];
	return (0);
}

int setenv_inbuilt(char **tokens)
{
	int x;

	x = set_env(tokens[1], tokens[2]);
	return (x);
}

int unsetenv_inbuilt(char **tokens)
{
	int x;

	x = unset_env(tokens[1]);
	return (x);
}
