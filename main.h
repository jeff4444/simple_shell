#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
extern char **environ;
char *_getenv(char *name);
int _putenv(char *name, char *string);
int _unsetenv(char **args, char **envp, char *argv, int count);
int _setenv(char **args, char **envp, char *argv, int count);
int handle_built(char **args, char **envp, char **argv, int count,
		char **reads, char *read);
int _setenv2(char *name, char *value, int overwrite);
int handle_cd(char **args, char **envp, char *argv, int count);
int print_env(char **args, char **envp, char **argv);
char **replace(char **args);
int execute_read(char *read, char **envp, char **argv, int count,
		char **reads, char *reader);
void *_realloc(void *ptr, unsigned int new);
char *print_nums(int n);
int _strlen(char *s);
char *str_add(char *filename);
void free_args(char **args);
char *_getdir(char *dir);
char *_strcpy(char *dest, char *src);
char *_strtok(char *srcString, char *delim);
int _strcmp(char *s1, char *s2);
char **tokenise(char *s);
void execute_command(char **args, char *stringexe, char **envp, char **av);
int checkexe(char *s);
char *string_add(void);
char *fix_path(char *filename);
int get_user_input(char **input);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _atoi(char *s);
int handle_exit(char **args, char **av, char **envp, int count,
		char **reads, char *read);
int print_env(char **args, char **envp, char **argv);
ssize_t _getline(char **lineptr, size_t *n, int fd);
int _putchar(char c);
void _puts(char *str);
void print_exit_error(char *av, int count, char *status);
void command_not_found(char *arg, int count, char *name);
void print_cd_error(char *argv, int count, char *name);
#endif
