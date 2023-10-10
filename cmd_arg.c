#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int length = 0;
	(void)ac;

	while (*av != NULL)
	{
		if (*av == NULL)
			break;
		printf("%s\n", *av);
		length++;
		av++;
	}
	return (length);
}
