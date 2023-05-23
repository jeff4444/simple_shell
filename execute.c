#include "main.h"
/**
 * execute_command - executes a command after fixing it
 * @args: arguments
 * @stringexe: executable file
 * @envp: environment variables
 * @av: argv
 *
 * Return: void
 */
void execute_command(char **args, char *stringexe, char **envp, char **av)
{
	(void)envp;
	if (execve(stringexe, args, environ) == -1)
	{
		perror(av[0]);
		exit(1);
	}
}
