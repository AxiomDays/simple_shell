#include "main.h"
/**
 * *handle_full_path - Entry point
 *
 * Description: 'handles the full path'
 * @f_path: char *f_path
 * Return: f_path
 */
char *handle_full_path(char *f_path)
{
	if (access(f_path, F_OK) == 0)
	{
		if (access(f_path, X_OK) == 0)
		{
			return (f_path);
		}
	}
	return (f_path);
}
