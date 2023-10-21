#include "shell.h"


/**
 * __exit - exits a process
 * @tokens: tokens of commands
 * Return: status
 */

int __exit(char **tokens)
{
	int code = errno;

	if (tokens[1] != NULL)
	{
		code = _atoi(tokens[1]);
		if (!_isdigit(tokens[1]) || code < 0)
		{
			return (2);
		}
	}
	else if (tokens[1] == NULL && code == 25)
		code = 0;
	_free(tokens);
	exit(code);
}

/**
 * __cd - changes to a directory
 * @tokens: tokens of commands
 * Return: status
 */

int __cd(char **tokens)
{
	char *folder = tokens[1];
	char pwd[4096], *home;
	int status_flag;
	int prev_flag = 0;

	getcwd(pwd, 4096);
	home = getenv("HOME");

	if (folder == NULL)
	{
		if (home)
			folder = home;
		else
			folder = pwd;
	}

	if (_strcmp(folder, "-") == 0)
	{
		prev_flag = 1;
		folder = getenv("OLDPWD");
		if (folder == NULL)
			folder = pwd;
	}

	status_flag = chdir(folder);
	if (status_flag == EXIT_SUCCESS)
	{
		setenv("OLDPWD", pwd, 1);
		getcwd(pwd, 4096);
		setenv("PWD", pwd, 1);
		if (prev_flag)
			write(STDOUT_FILENO, pwd, _strlen(pwd)),
			write(STDOUT_FILENO, "\n", 1);
	}

	return (status_flag);
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
		{"cd", __cd},
		{"setenv", setenv_inbuilt},
		{"unsetenv", unsetenv_inbuilt},
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
	errno = 0;
	return (EXIT_SUCCESS);
}
