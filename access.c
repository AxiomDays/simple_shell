#include "main.h"

char *_access(char **arr)
{
	int i = 0;

	printf("%s\n", arr[1]);
	while (arr[i])
	{
		/*printf("%d\n", i);*/
		if (access(arr[i], F_OK) == 0)
		{
			if (access(arr[i], X_OK) == 0)
			{
				return (arr[i]);
			}
		}
		i++;
	}
	return (arr[i]);
	
}
