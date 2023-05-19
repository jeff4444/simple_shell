#include "main.h"
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
	if (_strcmp(token, ""))
		return (_strtok(NULL, " "));
	return (token);
}
