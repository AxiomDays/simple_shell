#include "main.h"
/**
 * *_access - Entry point
 *
 * Description: 'checks if file exists and is executable then return'
 * @arr: char **arr
 * Return: Always 0 (Success)
 */
char *_access(char **arr)
{
	int i = 0;

	if (arr == NULL || arr[0] == NULL)
		return (NULL);
	while (arr[i])
	{
		if (access(arr[i], F_OK) == 0 && access(arr[i], X_OK) == 0)
		{
			return (arr[i]);
		}
		i++;
	}
	return (NULL);
}
