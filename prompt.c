#include "main.h"

char* prompt(void)
{	
	char* input;
	ssize_t text;	
	size_t bufsize = 32;

	input = (char *)malloc(bufsize * sizeof(char));

	printf("$ ");
	text = getline(&input, &bufsize, stdin);
	if (text == -1)
		exit(297);

	return (input);
}
