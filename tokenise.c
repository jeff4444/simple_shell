#include "main.h"
/**
 * tokenise - tokenises the read line
 * @s: read line
 *
 * Return: array of args
 */

char **tokenise(char *s)
{
	char *token, **args, *s_copy;
	size_t i = 0;
	int j;

	s_copy = malloc(sizeof(s));
	if (s_copy == NULL)
		return (NULL);
	strcpy(s_copy, s);
	token = strtok(s_copy, " ");
	if (token == NULL)
		return (NULL);

	while (token)
	{
		i++;
		token = strtok(NULL, " ");
	}

	args = malloc(i + 1);
	i = 0;
	token = strtok(s, " ");
	while (token)
	{
		j = 0;
		while (token[j] != '\0')
		{
			if (token[j] == '\n')
				token[j] = '\0';
			j++;
			if (_strcmp(token, ""))
				return (NULL);
		}
		args[i] = malloc(sizeof(token));
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
