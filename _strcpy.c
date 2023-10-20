#include "shell.h"

/**
 * _strcpy - copies a string
 * @s: string to be copied
 * @new_str: new string
 * Return: s
 */

char *_strcpy(char *new_str, char *s)
{
	size_t i = 0;

	while (*(s + i))
	{
		*(new_str + i) = *(s + i);
		i++;
	}
	*(new_str + i) = '\0';

	return (new_str);
}
