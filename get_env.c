#include "shell.h"

/**
 * _getenv - finds a path
 * @name: name of environment variable
 * Return: a string
 */

char *_getenv(char *name)
{
	int i = 0;

	while (environ[i])
	{
		if (_strncmp(environ[i], name, _strlen(name)) == 0)
		{
			return (environ[i]);
		}
		i++;
	}
	return (NULL);
}

/**
 * _strcmp - compares two strings
 * @s1: string
 * @s2: string
 * Return: int to determine comparism
 */

int _strcmp(char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (-1);
		s1++;
		s2++;
	}
	return (0);
}

/**
 * _strncmp - compares the first n bytes of two strings
 * @s1: first string
 * @s2: second string
 * @n: length to compare in each string
 * Return: int to determine comparism
 */

int _strncmp(char *s1, const char *s2, size_t n)
{
	while (n > 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
		{
			return (-1);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
