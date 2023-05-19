#include "main.h"


/**
 * tokenise_and_parse - tokenises the read line
 * @s: read line
 *
 * Return: array of args
 */
char **tokenise_and_parse(char *s)
{
	char *token, **args, *s_copy;
	int i = 0;
	int j;

	if (_strcmp(s, ""))
		return (NULL);
	s_copy = malloc(sizeof(s));
	if (s_copy == NULL)
		return (NULL);
	_strcpy(s_copy, s);
	token = _strtok(s_copy, " ");
	if (token == NULL)
	{
		free(s_copy);
		return (NULL);
	}
	args = malloc(MAX_ARGS * sizeof(char *));
	i = 0;
	token = _strtok(s, " ");
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
		token = _strtok(NULL, " ");
	}
	args[i] = NULL;
	free(s_copy);
	free(token);
	return (args);
}


/**
 * _strtok - tokenizes the string
 * @srcString: string to tokenize
 * @delim: list of delimiters
 *
 * Return: tokens
*/
char *_strtok(char *srcString, char *delim)
{
	static char *lastToken;
	char *token = NULL;

	if (srcString != NULL)
	{
		lastToken = srcString;
	}
	else if (lastToken == NULL)
	{
		return (NULL);
	}

	token = lastToken;

	while (*lastToken != '\0')
	{
		const char *p = delim;

		while (*p != '\0')
		{
			if (*lastToken == *p)
			{
				*lastToken = '\0';
				lastToken++;
				return (token);
			}

			p++;
		}

		lastToken++;
	}

	lastToken = NULL;
	return (token);
}
