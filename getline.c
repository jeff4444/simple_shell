#include "main.h"
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t i;

	i = read(fd, *lineptr, *n);
	return (i);
}
