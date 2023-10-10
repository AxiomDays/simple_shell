#include <stdio.h>
#include <stdlib.h>

int prompt(void)
{	
	char *input;	
	size_t bufsize = 32;
	size_t text;

	input = (char *)malloc(bufsize * sizeof(char));

	printf("$ ");
	text = getline(&input, &bufsize, stdin);
	printf("%s", input);
	(void)text;

	return (0);
}
