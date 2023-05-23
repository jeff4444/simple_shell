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

	s_copy = malloc(_strlen(s) + 1);
	if (s_copy == NULL)
		return (NULL);
	_strcpy(s_copy, s);
	token = _strtok(s_copy, " ");
	if (token == NULL)
	{
		free(s_copy);
		return (NULL);
	}
	while (token)
	{
		if (_strcmp(token, "#") || token[0] == '#')
			break;
		if (!(_strcmp(token, "")))
			i++;
		token = _strtok(NULL, " ");
	}
	args = malloc((i + 1) * sizeof(char *));
	i = 0;
	token = _strtok(s, " ");
	while (token)
	{
		if (_strcmp(token, "#") || token[0] == '#')
			break;
		if (!(_strcmp(token, "")))
		{
			args[i] = malloc(_strlen(token) + 1);
			_strcpy(args[i++], token);
		}
		token = _strtok(NULL, " ");
	}
	args[i] = NULL;
	if (!(_strcmp(token, "#") || token[0] == '#'))
		free(token);
	free(s_copy);
	return (args);
}
