#include "shell.h"

/**
 * _strcat - concatenates a string to another
 * @src: string to concatenate
 * @dest: string to be added to
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	size_t i = _strlen(dest);
	size_t j = 0;

	while (*(src + j))
	{
		*(dest + i) = *(src + j);
		j++;
		i++;
	}
	*(dest + i) = '\0';

	return (dest);
}
