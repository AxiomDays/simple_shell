#include "shell.h"


/**
 * getlne - gets line from user and execute command
 * @prompt: prompt to print
 * @program: name of program
 * @is_inter: an indicating if a terminal is on interactive mode or not
 */


void getlne(char *prompt, char *program, size_t is_inter)
{
	char *linebuff = NULL, *nl = "";
	size_t n = 0;
	ssize_t chars = 0;
	int x = 0;

	signal(SIGINT, sig_h);
	while (1)
	{
		x++;
		(is_inter) ? write(STDOUT_FILENO, prompt, _strlen(prompt))
			: write(STDOUT_FILENO, "", 0);
		chars = getline(&linebuff, &n, stdin);

		if (chars != -1)
			linebuff[chars - 1] = '\0';
		if (chars == 0)
		{
			write(STDOUT_FILENO, nl, 0);
			free(linebuff);
			continue;
		}
		if (chars == -1)
		{
			/*
			 * write(STDOUT_FILENO, "\n", 1);
			 */
			free(linebuff);
			exit(errno);
		}
		if (chars > 1)
		{
			tok_run(linebuff, x, program);
		}
		/*
		 * if (chars > 1 || chars == -1)
		{
			_free(tokens);
		}
		*/
	}
}

/**
 * non_getlne - gets line from user and execute command
 * @program: name of program
 */

void non_getlne(char *program)
{
	char *linebuff = NULL, *nl = "";
	size_t n = 0;
	ssize_t chars = 0;
	int x = 0;

	signal(SIGINT, sig_h);
	while (1)
	{
		x++;
		chars = getline(&linebuff, &n, stdin);
		if (chars != -1)
			linebuff[chars - 1] = '\0';
		if (chars == 0)
		{
			write(STDOUT_FILENO, nl, 0);
			free(linebuff);
			continue;
		}
		if (chars == -1)
		{
			/*
			 * write(STDOUT_FILENO, "\n", 1);
			 */
			free(linebuff);
			exit(errno);
		}
		if (chars > 1)
		{
			tok_run(linebuff, x, program);
		}
		/*
		 * if (chars > 1 || chars == -1)
		 * _free(tokens);
		 */
	}
}


/**
 * sig_h - handles ctr-c signal
 * @sig: signal
 */

void sig_h(int sig)
{
	if (sig == SIGINT)
	{
		errno = 130;
		write(STDOUT_FILENO, "\n", 1);

		if (isatty(STDOUT_FILENO))
		{
			write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		}
		fflush(stdout);
	}
}

/**
 * tok_run - tokenizes function for getlne and non_getlne
 * @linebuff: buffer
 * @x: counter for while loop
 * @program: program name
 * Return: integer
 */

int tok_run(char *linebuff, int x, char *program)
{
	char **faketok, **tokens;
	int j = 0;
	int built;

	faketok = colon_sep(linebuff);
	while (faketok[j])
	{
		tokens = sep(faketok[j]);
		if (tokens[0] == NULL)
		{
			errno = 0;
			_free(tokens);
			return (1);
		}
		if (_strcmp(tokens[0], "exit") == 0)
			free(linebuff), _free(faketok);
		built = inbuilts(tokens);
		if (built == 2)
		{
			fprintf(stderr, "%s: %d: %s: Illegal number: %s\n",
					program, x, tokens[0], tokens[1]);
			_free(tokens), exit(2);
		}
		if (built == -1)
		{
			fprintf(stderr, "%s: %d: %s: can't cd to %s\n"
					, program, x, tokens[0], tokens[1]);
			_free(tokens);
			continue;
		}
		if (built == NOT_INBUILT)
		{
			if (execute_bin(tokens) != 0)
			{
				errno = printerr(x, tokens[0], program);
			}
		}
		_free(tokens), free(faketok[j]), j++;
	} free(faketok);
	return (0);
}
