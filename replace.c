#include "main.h"
/**
 * replace - repaces variables
 * @args: list of cmd line arguments
 * Return: modified args
 */
char **replace(char **args)
{
	int n = 0;
	char *ptr, *ptr2, *get = NULL;

	while (args[n])
	{
		if (args[n][0] == '$')
		{
			if ((args[n][1] == '$') && args[n][2] == '\0')
			{
				/* still to implement this */
				get = print_nums(getpid());
				ptr2 = &args[n][0];
				args[n] = _realloc(ptr2, sizeof(get));
				_strcpy(args[n], get);
				free(get);
			}
			else
			{
				ptr = &args[n][1];
				ptr2 = &args[n][0];
				get = malloc(_strlen(_getenv(ptr)) + 1);
				_strcpy(get, _getenv(ptr));
				args[n] = _realloc(ptr2, sizeof(get));
				_strcpy(args[n], get);
				free(get);
			}
		}
		n++;
	}
	return (args);
}
