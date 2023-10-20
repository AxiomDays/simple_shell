#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#define vo (void)
#define NOT_INBUILT 4096
#define PROMPT "$ "

extern int errno;
extern char **environ;

/**
 * struct inbuilts - inbuilt command structure
 * @name: name of command
 * @func: name of function
 *
 * Description: Inbuilt command's structure
 */

typedef struct inbuilts
{
	char *name;
	int (*func)(char **);
} inbuilt_t;

size_t _strlen(char *str);
void getlne(char *prompt, char *, size_t);
void non_getlne(char *program);
char **sep(char *cmd);
int execute_bin(char **token);
void execute_cmd(char **tokens, char *path);
int _strcmp(char *s1, const char *s2);
char *_getenv(char *name);
char *_strdup(char *s);
char *_strcpy(char *, char *);
char *_strcat(char *dest, char *src);
char *getpath(char *path);
int printerr(int err, char *cmd, char *prog);
int _strncmp(char *s1, const char *s2, size_t n);
int inbuilts(char **tokens);
int __exit(char **tokens);
int _env(char **tokens);
void _free(char **arr);
void sig_h(int signal);
int _atoi(char *s);
int __cd(char **tokens);

#endif
