#ifndef TEST_H
#define TEST_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
typedef struct Path
{
	char *name;
	char *value;
	struct Path *next;
} path_t;
ssize_t _getline(char **lineptr, size_t *n, int fd);
#endif
