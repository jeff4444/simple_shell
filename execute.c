#include "main.h"
/**
 * execute_command - executes a command after fixing it
 * @args: arguments
 * @stringexe: executable file
 *
 * Return: void
 */
void execute_command(char **args, char *stringexe)
{
	if (execve(stringexe, args, NULL) == -1)
	{
		perror("Error!");
		exit(1);
	}
}
