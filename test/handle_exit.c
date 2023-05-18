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
int handle_exit(char **args, char **av, char **envp)
{
	int a;

	(void)envp;
	if (args[1] == NULL || _strcmp(args[1], "0"))
		exit(0);
	a = _atoi(args[1]);
	if (a == 0)
	{
		perror(av[0]);
		return (1);
	}
	exit(a);
}
