#include "shell.h"

/**
 * _strdup - duplicates a string
 * @s: string to be duplicated
 * Return: s
 */

char *_strdup(char *s)
{
	char *ptr;
	size_t i = 0;

	ptr = malloc(_strlen(s) + 1 * sizeof(ptr));
	if (ptr == NULL)
	{
		return (NULL);
	}

	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';

	return (ptr);
}
