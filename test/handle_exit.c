#include "main.h"
/**
 * handle_exit - handles the exit command
 * @args: command line args
 * @envp: environment variables
 * @av: command used to run file
 * @count: current count
 *
 * Return: int
 */
int handle_exit(char **args, char **av, char **envp, int count)
{
	int a;

	(void)envp;
	if (args[1] == NULL || _strcmp(args[1], "0"))
		exit(0);
	a = _atoi(args[1]);
	if (a == 0)
	{
		_printf("%s: %d: %s: Illegal number: %s\n", av[0], count, args[0], args[1]);
		return (1);
	}
	exit(a);
}
