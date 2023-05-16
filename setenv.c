#include "main.h"
/**
 * _setenv -  changes or adds an environment variable
 * @name: variable name
 * @value: new value
 * @overwrite: describes if the operation should overwite
 * any already declared environment variable or not
 *
 * Return: int
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *init_value, *output, *init_name;
	int i = 0;

	if (name == NULL || value == NULL || name[0] == '\0')
		return (-1);
	init_value = getenv(name);
	init_name = malloc(sizeof(name));
	while (name[i] != '\0')
	{
		init_name[i] = name[i];
		i++;
	}
	init_name[i] = '\0';
	i = 0;
	init_name = strcat(init_name, "=");
	output = strcat(init_name, value);
	if (!init_value || overwrite)
		i = putenv(output);
	if (i == 0)
		return (0);

	return (-1);
}

/**
 * _unsetenv - removes and environment variable
 * @name: variable name
 *
 * Return: int
 */
int _unsetenv(char *name)
{
	int i;

	if (name == NULL || name[0] == '\0')
		return (-1);
	strcat(name, "=");
	i = putenv(name);
	if (i == 0)
		return (0);
	return (-1);
}
