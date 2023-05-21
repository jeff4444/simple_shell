#include "main.h"
/**
 * _getenv - gets environment variable
 * @name: name of environment variable
 * Return: value
 */
char *_getenv(char *name)
{
	int i = 0, j, on;
	char *value = NULL;

	while (environ[i] != NULL)
	{
		j = 0;
		on = 0;
		while (name[j] != '\0')
		{
			if (name[j] != environ[i][j])
				on = 1;
			j++;
		}
		if (on)
		{
			i++;
			continue;
		}
		if (environ[i][j] == '=')
		{
			j++;
			value = &environ[i][j];
			return (value);
		}
		i++;
	}
	return (NULL);
}

/**
 * _putenv - replaces or adds an environment vriable
 *
 * @name: name of environment variable
 * @string: env variable in the form "name=value"
 * Return: int
 */
int _putenv(char *name, char *string)
{
	int i = 0, j, on;
	char *env_var;

	while (environ[i])
	{
		j = 0;
		on = 0;
		while (name[j] != '\0')
		{
			if (name[j] != environ[i][j])
				on = 1;
			j++;
		}
		if (on)
		{
			i++;
			continue;
		}
		/* maiin substitution here */
		env_var = malloc(_strlen(string) + 1);
		_strcpy(env_var, string);
		environ[i] = env_var;
		return (0);
	}
	environ[i] = string;
	i++;
	environ[i] = NULL;
	return (0);
}
