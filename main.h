#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

extern int err_count;
extern char *progName;

int check_pid(void);
char* prompt(void);
char *_strcpy(char *dest, char *src);
char *_access(char **arr);
char** check_path(char *cmd);
void print_err_mes(void);
int _putchar(char c);
int _print(char *str);
void print_number(int n);
void free_2d(char **ptr);
char *handle_full_path(char *f_path);

#endif
