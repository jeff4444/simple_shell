#include "main.h"
/**
 * replace - repaces variables
 * @args: list of cmd line arguments
 * @i: int
 * Return: modified args
 */
char **replace(char **args, int *i)
{
	int n = 0;
	char *ptr, *ptr2, *get = NULL;

	while (args[n])
	{
		if (args[n][0] == '$')
		{
			if ((args[n][1] == '$') && args[n][2] == '\0' &&
					_strcmp(args[n - 1], "echo"))
			{
				/* still to implement this */
				_printf("%d\n", getpid());
				*i = 100;
				break;
			}
			else if (!_strcmp(args[n - 1], "echo"))
			{
				n++;
				continue;
			}
			else
			{
				ptr = &args[n][1];
				ptr2 = &args[n][0];
				get = malloc(_strlen(_getenv(ptr)) + 1);
				_strcpy(get, _getenv(ptr));
				args[n] = realloc(ptr2, sizeof(get));
				_strcpy(args[n], get);
			}
		}
		n++;
	}
	free(get);
	return (args);
}
