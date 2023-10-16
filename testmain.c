#include "main.h"

int main(void)
{
	int i = 0, x = 0;
	int status;
	char *input;
	char *tok, *ptr;
	char **arr;
	char **path;
	pid_t pid;


	while (1)
	{
		i = 0, x = 0;
		input = prompt();
		printf("%s\n", input);
		tok = strtok(input, " \n");
		arr = malloc(sizeof(char *) * 1024);
		path = malloc(sizeof(char*) * 1024);

		while (tok)
		{
			arr[i] = tok;
			tok = strtok(NULL, " \n");
			i++;
		}
			arr[i] = NULL;

			path = check_path(arr[0]);
			ptr = _access(path);
			if (ptr == NULL)
				exit(1);
			arr[0] = ptr;
			pid = fork();

			if (pid == 0)
			{
				if(execve(arr[0], arr, NULL) == -1)
					return (-1);
			}
			else
			{
				wait(&status);
			}
		while (x < 1024)
			{
				free(arr[x]);
				x++;
			}
		free(arr);
		free(path);
	}	
	return 0;
}
