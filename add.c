#include "main.h"
/**
 * string_add - provides the string needed to fix path
 * Return: the string
 */
char *string_add(void)
{
	char *add = malloc(6);

	add[0] = '/';
	add[1] = 'b';
	add[2] = 'i';
	add[3] = 'n';
	add[4] = '/';
	add[5] = '\0';

	return (add);
}
