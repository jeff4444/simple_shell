#include "main.h"
/**
 * _setenv -  changes or adds an environment variable
 * @args: command line arguments
 * @envp: environment variables
 * @argv: current exe filename
 * @count: count
 * Return: int
 */
int _setenv(char **args, char **envp, char *argv, int count)
{
	char *init_value, *output;
	int i = 0, overwrite = 1;
	size_t name_len, val_len;

	(void)envp;
	(void)argv;
	(void)count;
	if (args[1] == NULL || args[2] == NULL || args[1][0] == '\0')
	{
		_printf("Error\n");
		return (1);
	}
	name_len = _strlen(args[1]);
	val_len = _strlen(args[2]);
	output = malloc(name_len + val_len + 2);

	_strcpy(output, args[1]);
	output[name_len] = '=';
	_strcpy(output + name_len + 1, args[2]);
	output[name_len + val_len + 1] = '\0';
	init_value = malloc(_strlen(_getenv(args[1])) + 1);
	_strcpy(init_value, _getenv(args[1]));

	if (!init_value || overwrite)
		i = _putenv(args[1], output);
	if (i)
		_printf("Error\n");
	free(init_value);
	free(output);
	return (1);
}


/**
 * _unsetenv - removes and environment variable
 * @args: command line arguments
 * @envp: environment variables
 * @argv: current exe filename
 * @count: count
 *
 * Return: int
 */
int _unsetenv(char **args, char **envp, char *argv, int count)
{
	char *name = malloc(_strlen(args[1]) + 2);
	int i;

	(void)envp;
	(void)argv;
	(void)count;
	if (args[1] == NULL || args[1][0] == '\0')
	{
		_printf("Error\n");
		return (1);
	}
	_strcpy(name, args[1]);
	_strcpy(name + _strlen(args[1]), "=");
	name[_strlen(args[1]) + 1] = '\0';
	i = _putenv(name, name);
	if (i)
		_printf("Error\n");
	free(name);
	return (1);
}
