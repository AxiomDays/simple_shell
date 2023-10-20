#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * **check_path - Entry point
 *
 * Description: 'recieves command and appends it to all
 * possible paths before sending to access function'
 * @cmd: char *cmd
 * Return: Always 0 (Success)
 */
char **check_path(char *cmd)
{
	char *path, *tok, *buff;
	char **arr = NULL;
	char **newarr = NULL;
	int i = 0, j = 0;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	buff = strdup(path);
	tok = strtok(buff, ":");
	while (tok)
	{
		i++;
		tok = strtok(NULL, ":");
	}
	arr = (char **)malloc(sizeof(char *) * (i + 1));
	newarr = (char **)malloc(sizeof(char *) * (i + 1));
	strcpy(buff, path);
	i = 0;
	tok = strtok(buff, ":");
	while (tok)
	{
		arr[i] = strdup(tok);
		tok = strtok(NULL, ":");
		i++;
	}
	for (j = 0; j < i; j++)
	{
		newarr[j] = (char *)malloc(strlen(arr[j]) + strlen(cmd) + 2);
		strcpy(newarr[j], arr[j]);
		strcat(newarr[j], "/");
		strcat(newarr[j], cmd);
	}
	free(buff);
	/*for (j = 0; j < i; j++)
	{
		free(arr[j]);
	}
	free(arr);*/
	if (arr != NULL)
		free_2d(arr);
	return (newarr);
}
