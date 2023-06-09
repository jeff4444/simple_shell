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

	UNUSED(envp);
	UNUSED(argv);
	UNUSED(count);
	if (args[1] == NULL || _strcmp(args[1], "0"))
		exit(0);
	if (_strcmp(args[1], ""))
		exit(0);
	a = _atoi(args[1]);
	if (a == 0)
	{
		_puts("Illegal Argument\n");
		return (1);
	}
	exit(a);
}

