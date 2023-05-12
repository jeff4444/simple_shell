#include "test.h"
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t i;

	printf("Here");
	fflush(stdout);
	i = read(fd, *lineptr, *n);
	printf("%lu", i);
	fflush(stdout);
	return (i);
}
