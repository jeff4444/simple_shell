#include "main.h"
/**
 * handle_exit - handles the exit command
 * @args: command line args
 * @envp: environment variables
 * @argv: command used to run file
 * @count: current count
 *
 * Return: int
 */
int handle_exit(char **args, char **envp, char *argv, int count)
{
	int a;
	char **endptr = NULL;

	UNUSED(envp);
	if (args[1] == NULL || _strcmp(args[1], "0"))
		exit(0);
	a = strtod(args[1], endptr);
	if (a == 0)
	{
		if (!_strcmp(args[1], ""))
			printf("%s: %d: %s: Illegal number: %s\n", argv, count, args[0], args[1]);
		else if (_strcmp(args[1], ""))
			printf("%s: %d: %s: Illegal argument\n", argv, count, args[0]);
		return (1);
	}
	exit(a);
}
