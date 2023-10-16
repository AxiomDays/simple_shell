#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *path, *tok;
	char **arr = malloc(sizeof(char*) * 1024);
	/*char **cpy = malloc(sizeof(char*) * 1024);*/
	char *cmd = "ls", *str;
	int i = 0;

	path = getenv("PATH");
	printf("%s\n", path);

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
			if (access(str, F_OK) == 0)
			{
				if (access(str, X_OK) == 0)
				{
					printf("Is executable\n");
				}
				else
				{
					printf("Permission denied\n");
				}
			}
			else
			{
				printf("File not found\n");
			}
			i++;
		}

	return (0);
}
