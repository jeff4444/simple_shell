#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#define UNUSED(x) (void)(x)
#define MAX_ARGS 10 /* Maximum number of arguments */
/**
 * struct Builtin - built ins
 * @name: name of built in
 * @func: function to be called
 */
typedef struct Builtin
{
	char *name;
	int (*func)(char **, char **, char *, int);
} built_in;
char **replace(char **args, int *i);
int handle_exit(char **args, char **envp, char *argv, int count);
int handle_cd(char **args, char **envp, char *argv, int count);
char **tokenise_and_parse(char *s);
void execute_command(char **args, char *stringexe, char **envp);
int checkexe(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *string_add(void);
char *fix_path(char *filename);
int print_env(char **args, char **envp, char *argv, int count);
int get_user_input(char **input);
int handle_builtin_cmds(char *input, char **args, char **envp,
		char *argv, int count);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _setenv(char **args, char **envp, char *argv, int count);
int _unsetenv(char **args, char **envp, char *argv, int count);
char *_strtok(char *srcString, char *delim);
int _atoi(char *s);
void _puts(char *str);
int _putchar(char c);
#endif
