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
	char *name = args[1], *value = args[2];
	char *init_value, *output, *init_name;
	int i = 0, overwrite = 1;

	(void)envp;
	(void)argv;
	(void)count;
	if (name == NULL || value == NULL || name[0] == '\0')
	{
		_printf("Error\n");
		return (1);
	}
	init_value = _getenv(name);
	init_name = malloc(sizeof(name));
	while (name[i] != '\0')
	{
		init_name[i] = name[i];
		i++;
	}
	init_name[i] = '\0';
	i = 0;
	init_name = _strcat(init_name, "=");
	output = _strcat(init_name, value);
	if (!init_value || overwrite)
		i = _putenv(args[1], output);
	if (i)
		_printf("Error\n");

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
	char *name = args[1];
	int i;

	(void)envp;
	(void)argv;
	(void)count;
	if (name == NULL || name[0] == '\0')
	{
		_printf("Error\n");
		return (1);
	}
	_strcat(name, "=");
	i = _putenv(name, name);
	if (i)
		_printf("Error\n");
	return (1);
}
