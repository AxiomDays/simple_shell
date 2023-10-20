#include "shell.h"

/**
 * _free - frees an allocated array
 * @arr: the array
 */

void _free(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

