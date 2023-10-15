#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	extern char **environ;
	char *path, *tok;
	char **arr = malloc(sizeof(char*) * 1024);
	char **cpy = malloc(sizeof(char*) * 1024);
	char *cmd = "/ls";
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
			cpy[i] = arr[i];
			strcat(cpy[i], cmd);
			printf("%s\n", cpy[i]);
			i++;
		}

	return (0);
}
