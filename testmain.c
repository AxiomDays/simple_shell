#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	int i = 0;
	int status;
	char *input;
	char *tok;
	char **arr;
	pid_t pid;


	while (1)
	{
		input = prompt();
		printf("%s\n", input);
		tok = strtok(input, " \n");
		arr = malloc(sizeof(char *) * 1024);

		while (tok)
		{
			arr[i] = tok;
			tok = strtok(NULL, " \n");
			i++;
		}
			arr[i] = NULL;
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
		i = 0;
		free(arr);
	}	
	return 0;
}
