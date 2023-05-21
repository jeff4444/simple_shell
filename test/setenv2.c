#include "main.h"
/**
 * _setenv2 -  changes or adds an environment variable
 * @name: name of env variable
 * @value: value of env variable
 * @overwrite: 1 (true) 0 (false)
 *
 * Return: int
 */
int _setenv2(char *name, char *value, int overwrite)
{
	char *init_value;
	int i = 0;
	size_t name_len, val_len;
	char *output;

	if (name == NULL || value == NULL || name[0] == '\0')
	{
		_printf("Error\n");
		return (1);
	}
	name_len = _strlen(name);
	val_len = _strlen(value);
	output = malloc(name_len + val_len + 2);

	_strcpy(output, name);
	output[name_len] = '=';
	_strcpy(output + name_len + 1, value);
	output[name_len + val_len + 1] = '\0';
	init_value = malloc(_strlen(_getenv(name)) + 1);
	_strcpy(init_value, _getenv(name));
	if (!init_value || overwrite)
		i = _putenv(name, output);
	if (i)
		_printf("Error\n");
	free(init_value);
	free(output);
	return (1);
}
