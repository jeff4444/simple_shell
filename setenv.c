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

	UNUSED(envp);
	UNUSED(argv);
	UNUSED(count);
	if (name == NULL || value == NULL || name[0] == '\0')
	{
		perror("Error\n");
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
		i = putenv(output);
	if (i)
		perror("Error\n");

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

	UNUSED(envp);
	UNUSED(argv);
	UNUSED(count);
	if (name == NULL || name[0] == '\0')
	{
		printf("Error\n");
		return (1);
	}
	_strcat(name, "=");
	i = putenv(name);
	if (i)
		printf("Error\n");
	return (1);
}


/**
 * _getenv - this gets the value of the global variable
 * @name: name of the global variable
 * Return: string of value
 */
char *_getenv(const char *name)
{
	int a, b;
	char *val;

	if (!name)
		return (NULL);
	for (a = 0; environ[a]; a++)
	{
		b = 0;
		if (name[b] == environ[a][b])
		{
			while (name[b])
			{
				if (name[b] != environ[a][b])
					break;

				b++;
			}
			if (name[b] == '\0')
			{
				val = (environ[a] + b + 1);
				return (val);
			}
		}
	}
	return (0);
}

