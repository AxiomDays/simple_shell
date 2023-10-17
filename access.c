#include "main.h"

char *_access(char **arr)
{
    int i = 0;

    if (arr == NULL || arr[0] == NULL) {
        return (NULL);
    }


    while (arr[i])
    {
        if (access(arr[i], F_OK) == 0 && access(arr[i], X_OK) == 0)
        {
            return (arr[i]);
        }
        i++;
    }

    return (NULL);
}
