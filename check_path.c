#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char** check_path(char *cmd)
{
	char *path, *tok;
	char **arr = malloc(sizeof(char*) * 1024);
	char **newarr = malloc (sizeof(char*) * 1024);
	char *str;
	int i = 0;

	path = getenv("PATH");

	tok = strtok(path, ":");
	while (tok)
	{
		arr[i] = tok;
		tok = strtok(NULL, ":");
		i++;
	}
	i = 0;
	while (arr[i])
		{
			str = strdup(arr[i]);
			strcat(str, "/");
			strcat(str, cmd);
			newarr[i] = str;
			i++;
		}
	
	free(arr);
	free(str);
	return (newarr);
}
