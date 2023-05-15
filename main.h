#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
int handle_cd(char **args);
int _strcmp(char *s1, char *s2);
char **tokenise(char *s);
void execute_command(char **args, char *stringexe, char **envp);
int checkexe(char *s);
char *_strcat(char *s1, char *s2);
char *string_add(void);
char *fix_path(char *filename);
void print_env(char **envp);
int get_user_input(char **input);
int handle_builtin_cmds(char *input, char **args, char **envp,
		char *argv, int count);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
