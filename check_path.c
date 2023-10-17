#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** check_path(char *cmd)
{
    char *path, *tok;
    char **arr = NULL;
    char **newarr = NULL;
    char *buff;
    int i = 0, j = 0;

    path = getenv("PATH");
    if (!path) {
        return NULL; /* Handle the case where PATH is not set.*/
    }

    buff = strdup(path);

    /* Count the number of paths*/
    tok = strtok(buff, ":");
    while (tok)
    {
        i++;
        tok = strtok(NULL, ":");
    }

    /* Allocate memory for arr and newarr*/
    arr = (char**)malloc(sizeof(char*) * (i + 1));
    newarr = (char**)malloc(sizeof(char*) * (i + 1));

    /* Reset buff and i*/
    strcpy(buff, path);
    i = 0;

    tok = strtok(buff, ":");
    while (tok)
    {
        arr[i] = strdup(tok);
        tok = strtok(NULL, ":");
        i++;
    }

    /* Append cmd to each path and store in newarr*/
    for (j = 0; j < i; j++)
    {
        newarr[j] = (char*)malloc(strlen(arr[j]) + strlen(cmd) + 2); /* +2 for '/' and null terminator*/
        strcpy(newarr[j], arr[j]);
        strcat(newarr[j], "/");
        strcat(newarr[j], cmd);
    }

    free(buff);

    /* Free arr since its content is duplicated in newarr*/
    for (j = 0; j < i; j++)
    {
        free(arr[j]);
    }
    free(arr);

    return newarr;
}
