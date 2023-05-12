#include "main.h"
/**
 * fix_path - fixes path provided file exists
 * @filename: file name
 * Return: fixed file name
 */
char *fix_path(char *filename)
{
	char *add = string_add();
	char *stringexe;
	int n = checkexe(filename);

	if (n)
		stringexe = strcat(add, filename);
	else
		stringexe = filename;
	return (stringexe);
}
