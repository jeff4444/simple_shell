#include "main.h"
/**
 * tokenise - tokenises the read line
 * @s: read line
 *
 * Return: array of args
 */

char **tokenise_and_parse(char *s)
{
	char *token, **args, *s_copy;
	int i = 0;
	int j;

	s_copy = malloc(sizeof(s));
	if (s_copy == NULL)
		return (NULL);
	strcpy(s_copy, s);
	token = my_strtok(s_copy, " ");
	if (token == NULL)
	{
		free(s_copy);
		return (NULL);
	}
	while (token)
	{
		i++;
		token = my_strtok(NULL, " ");
	}
	args = malloc((i + 1) * sizeof(char *));
	i = 0;
	token = my_strtok(s, " ");
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
		strcpy(args[i++], token);
		token = my_strtok(NULL, " ");
	}
	args[i] = NULL;
	free(s_copy);
	free(token);
	return (args);
}

/**
 * is_delim - test whether the string is delimited
 * @c: string to test
 * @delims: list of delimiters
 * Returns: 1 if the string is delimited else 0
*/
unsigned int is_delim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return 1;
        delim++;
    }
    return 0;
}

/**
 * my_strtok - tokenize the string
 * @srcString: string to tokenize
 * @delim: list of delimiters
 * Returns: tokens
*/
char *my_strtok(char *srcString, char *delim)
{
    static char *backup_string; /*start of the next search*/
    char *ret;

	if(!srcString)
    {
        srcString = backup_string;
    }
    if(!srcString)
    {
        /* user is bad user */
        return NULL;
    }
    /* handle beginning of the string containing delims */
    while(1)
    {
        if(is_delim(*srcString, delim))
        {
            srcString++;
            continue;
        }
        if(*srcString == '\0')
        {
            /* we've reached the end of the string */
            return NULL; 
        }
        break;
    }

	ret = srcString;
    while(1)
    {
        if(*srcString == '\0')
        {
            /*end of the input string and
            next exec will return NULL*/
            backup_string = srcString;
            return ret;
        }
        if(is_delim(*srcString, delim))
        {
            *srcString = '\0';
            backup_string = srcString + 1;
            return ret;
        }
        srcString++;
    }
}