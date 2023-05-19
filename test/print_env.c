#include "main.h"
/**
 * print_env - prints current environment
 * @args: command line arguments
 * @envp: environment variables
 * @argv: current exe filename
 * Return: int
 */
int print_env(char **args, char **envp, char **argv)
{
	int i = 0;

	if (args[1] != NULL)
	{
		perror(argv[0]);
		return (1);
	}
	while (envp[i])
	{
		write(STDOUT_FILENO, envp[i], sizeof(envp[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}
