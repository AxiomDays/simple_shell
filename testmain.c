#include "main.h"

int err_count = 0;
char *progName;
char *input;

int main(int argc, char **argv)
{
	int i = 0;
	int status;
	char *tok, *ptr;
	char **arr;
	char **path;
	pid_t pid;

	progName = argv[0];
	(void)argc;

	while (1)
	{
		i = 0;
		input = prompt();
		if (strlen(input) == 0)
		{
			continue;
		}

		tok = strtok(input, " \n");
		arr = malloc(sizeof(char *) * 4096);
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
			print_err_mes();
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
		free_2d(arr);
		free(arr);
		/*free_2d(path);*/
		free(path);
		free(input);
	}	
	return 0;
}
