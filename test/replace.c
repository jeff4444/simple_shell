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
	char *ptr, *ptr2, *get;

	while (args[n])
	{
		if (args[n][0] == '$')
		{
			if ((args[n][1] == '$') && args[n][2] == '\0')
			{
				printf("%u\n", getpid());
				*i = 100;
				break;
			}
			else
			{
				ptr = &args[n][1];
				ptr2 = &args[n][0];
				get = getenv(ptr);
				args[n] = realloc(ptr2, sizeof(get));
				strcpy(args[n], get);
			}
		}
		n++;
	}
	return (args);
}
