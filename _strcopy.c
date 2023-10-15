#include "main.h"
#include <unistd.h>
#include <string.h>
/**
 * _strcpy - copy the string pointed to by src to dest
 * @dest: char to check
 * @src: char to check
 * Return: 0 is success
 */
char *_strcpy(char *dest, char *src)
{
	int a;
	int len;

	len = strlen(src);

	for (a = 0; a < (len+1); a++)
		dest[a] = src[a];
	return (dest);
}
