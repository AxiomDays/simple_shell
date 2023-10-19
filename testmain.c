#include "main.h"

int err_count = 0;
char *progName;
char *input;

int main(int argc, char **argv)
{
	char *ptr, **arr;
	char **path = NULL;
	pid_t pid;
	progName = argv[0];
	(void)argc;

	while (1)
	{
		input = prompt();
		if (input == NULL)
		{
			free(input);
			continue;
		}
		arr = tok_array(input);
		if (!arr)
		{
			print_err_mes();
			free(input);
			continue;
		}
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
			free(input);		
			continue;
		}
		arr[0] = ptr;
		pid = fork();
		pid_check(pid, arr);
		free_2d(arr);
		free(input);
	}	
	return 0;
}

char** tok_array(char* input)
{
	int i = 0;
	char *tok;
	char **arr = NULL;
	char *buf = NULL;

	buf = strdup(input);
	tok = strtok(buf, " \n");
	while (tok)
	{
		i++;
		tok = strtok(NULL, " \n");
	}
	arr = (char **)malloc(sizeof(char *) * (i + 1));
	if (!arr)
	{
		print_err_mes();
		free_2d(arr);
		exit(errno);
	}
	strcpy(buf, input);
	i = 0;
	tok = strtok(buf, " \n");
	while (tok)
	{
		arr[i] = strdup(tok);
		if (!arr[i])
		{
			print_err_mes();
			free_2d(arr);
			exit(errno);
		}
		tok = strtok(NULL, " \n");
		i++;
	}
	free(buf);
	return (arr);
}

int pid_check (pid_t pid, char** arr)
{
	int status;

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
				free_2d(arr);
                                exit(errno);
                        }
                }
                else
                {
                        wait(&status);
                }
		return 0;
}

