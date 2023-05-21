#include "main.h"


/**
 * tokenise_and_parse - tokenises the read line
 * @s: read line
 *
 * Return: array of args
 */
char **tokenise_and_parse(char *str, const char *delim)
{
	int i, wn;
	char **array;
	char *token, *buffer;

	buffer = malloc(_strlen(str) + 1);
	if (buffer == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';

	token = _strtok(buffer, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	i = 1;
	wn = 3;
	while (token)
	{
		token = _strtok(NULL, delim);
		array = _realloc(array, (sizeof(char *) * (wn - 1)), (sizeof(char *) * wn));
		array[i] = _strdup(token);
		i++;
		wn++;
	}
	free(buffer);
	return (array);
}


/**
 * _strtok - tokenizes the string
 * @srcString: string to tokenize
 * @delim: list of delimiters
 *
 * Return: tokens
*/
char *_strtok(char *srcString, char const *delim)
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
