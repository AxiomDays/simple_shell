#include "main.h"

char* prompt(void)
{	
	char* inp;
	ssize_t text;	
	size_t bufsize = 32; /*, len;*/

	inp = NULL;
	/*if (!inp)
	{
		print_err_mes();
		exit(errno);
	}*/

	printf("$ ");
	text = getline(&inp, &bufsize, stdin);
	/*len = strlen(inp);
	inp[len - 1] = '\0';*/

	if (text == -1)
	{
		free(inp);
		exit(297);
	}
	return (inp);
}
