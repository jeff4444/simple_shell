#include "main.h"
/**
 * fix_path - fixes path provided file exists
 * @filename: file name
 * Return: fixed file name
 */
char *fix_path(char *filename)
{
	char *stringexe;
	int n = checkexe(filename);

	if (n)
		stringexe = str_add(filename);
	else
	{
		stringexe = malloc(_strlen(filename) + 1);
		_strcpy(stringexe, filename);
	}
	return (stringexe);
}

/**
 * str_add - adds "/bin/" to a string
 * @filename: string
 * Return: result
 */
char *str_add(char *filename)
{
	size_t i = _strlen(filename);
	char *add = malloc(i + 1 + 6);

	if (add == NULL)
		return (NULL);
	_strcpy(add, "/bin/");
	_strcpy(add + 5, filename);
	add[i + 5] = '\0';

	return (add);
}
