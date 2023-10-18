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
		arr = (char **)malloc(sizeof(char *) * 4096);
		if (!arr)
		{
			print_err_mes();
			exit(errno);
		}
		while (tok)
		{
			arr[i] = strdup(tok);
			if (!arr[i])
			{
				print_err_mes();
				exit(errno);
			}
			tok = strtok(NULL, " \n");
			i++;
		}

		arr[i] = NULL;

		if (arr[0][0] == '/')
		{
			ptr = handle_full_path(arr[0]);
		}
		else
		{
			path = check_path(arr[0]);
			ptr = _access(path);
		}

		if (ptr == NULL)
		{
			print_err_mes();
			free_2d(arr);
			free(arr);
			free(input);
			continue;
		}

		arr[0] = ptr;

		pid = fork();

		if (pid == -1)
		{
			print_err_mes();
			exit(errno);
		}
		else if (pid == 0)
		{
			if(execve(arr[0], arr, NULL) == -1)
			{
				print_err_mes();
				exit(errno);
			}
		}
		else
		{
			wait(&status);
		}
		free_2d(arr);
		free_2d(path);
		free(input);
	}	
	return 0;
}
