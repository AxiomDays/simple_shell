#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

int main(void)
{
	pid_t pid;
	int status;
	int n;
	pid_t ppid;

	for (n = 0; n < 5; n++)
	{
	pid = fork();
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	if (pid == 0)
	{	
		ppid = getppid();
		printf("Child Done, %i\n", ppid);
		if (execve(argv[0], argv, NULL) == -1)
			return (-1);
	}
	else
	{
		wait(&status);
		printf("Parent Done\n");
	}
	}
	return 0;
}
