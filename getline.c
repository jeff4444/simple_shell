#include "main.h"
/**
 * _getline - getline function
 * @lineptr: line pointer
 * @n: size of lineptr
 * @stream: File stream to read from
 * Return: size read or -1 (Fail)
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char *buffer;
	static size_t n_chars;
	size_t i = 0;
	int ch;
	static int p = 1;

	if (buffer == NULL)
	{
		n_chars = BUFSIZ;
		buffer = malloc(n_chars);
		if (buffer == NULL)
			return (-1);
	}
	while ((ch = fgetc(stream)) != EOF)
	{
		if (ch == '\n')
			break;
		buffer[i++] = ch;
		if (i == (n_chars * p))
		{
			p++;
			n_chars *= p;
			buffer = realloc(buffer, n_chars);
			if (buffer == NULL)
				return (-1);
		}
		if (buffer == NULL)
			return (-1);
	}

	buffer[i] = '\0';
	*lineptr = buffer;
	*n = n_chars;

	if (ch == EOF && i == 0)
		return (-1);
	else
		return (i);
}
