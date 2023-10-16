#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
int check_pid(void);
char* prompt(void);
char *_strcpy(char *dest, char *src);
char *_access(char **arr);
char** check_path(char *cmd);
