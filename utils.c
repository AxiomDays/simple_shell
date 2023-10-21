#include "shell.h"

/**
 * _isdigit - Checks if a string contains onl digits
 * @input: String to check
 * Return: 1 if true else 0
 */
int _isdigit(char *input)
{

	int i = 0;

	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
