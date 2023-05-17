#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char **tokenise(char *s);
void execute_command(char **args, char *stringexe, char **envp);
int checkexe(char *s);
char *string_add(void);
char *fix_path(char *filename);
int get_user_input(char **input);
char *_strcat(char *dest, char *src);
#endif
