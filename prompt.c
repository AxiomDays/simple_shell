#include "main.h"

char* prompt(void)
{	
	char* inp;
	ssize_t text;	
	size_t bufsize = 32;

	inp = (char *)malloc(bufsize * sizeof(char));

	printf("$ ");
	text = getline(&inp, &bufsize, stdin);

	if (text == -1)
		exit(297);

	return (inp);
}
