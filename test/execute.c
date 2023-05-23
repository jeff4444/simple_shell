#include "main.h"
/**
 * execute_command - executes a command after fixing it
 * @args: arguments
 * @stringexe: executable file
 * @envp: environment variables
 *
 * Return: void
 */
void execute_command(char **args, char *stringexe, char **envp)
{
	if (execve(stringexe, args, envp) == -1)
	{
		perror("Error!");
		exit(1);
	}
}
