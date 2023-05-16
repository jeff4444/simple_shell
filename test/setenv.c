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
extern char **environ;
int _setenv(const char *name, const char *value, int overwrite)
{
	char *init_value, *output, *init_name;
	int i = 0, j = 0;

	init_value = getenv(name);
	init_name = malloc(sizeof(name));
	while (name[i] != '\0')
	{
		init_name[i] = name[i];
		i++;
	}
	init_name[i] = '\0';
	i = 0;
	if (!init_value)
	{
		while (environ[i])
			i++;
		init_name = strcat(init_name, "=");
		environ[i] = strcat(init_name, value);
		i++;
		environ[i] = NULL;
	}
	else
	{
		if (overwrite)
		{
			init_name = strcat(init_name, "=");
			output = strcat(init_name, value);
			while (environ[i])
			{
				if (_strcmp(environ[i], output))
				{
					environ[i] = realloc(environ[i], sizeof(output));
					if (environ[i] == NULL)
						return (-1);
					while (output[j] != '\0')
					{
						environ[i][j] = output[j];
					}
					environ[i][j] = '\0';
				}
			}
		}
	}

	return (0);
}
