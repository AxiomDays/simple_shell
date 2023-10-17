#include "main.h"

char** check_path(char *cmd)
{
	char *path, *tok;
	char **arr = malloc(sizeof(char*) * 1024);
	char **newarr = malloc (sizeof(char*) * 1024);
	char *str = malloc(sizeof(char *));
	
	char *buff;
	int i = 0;

	path = getenv("PATH");
	printf("%s", path);
	buff = strdup(path);

	tok = strtok(buff, ":");
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
	
	/*free_2d(arr);*/
	free(arr);
	free(str);
	free(buff);
	return (newarr);
}
