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
	int i = 0;
	int j;

	s_copy = malloc(sizeof(s));
	if (s_copy == NULL)
		return (NULL);
	_strcpy(s_copy, s);
	token = strtok(s_copy, " ");
	if (token == NULL)
	{
		free(s_copy);
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, " ");
	}
	args = malloc((i + 1) * sizeof(char *));
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
		}
		args[i] = malloc(sizeof(char) * (j + 1));
		_strcpy(args[i++], token);
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	free(s_copy);
	free(token);
	return (args);
}
