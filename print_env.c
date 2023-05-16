#include "main.h"
/**
 * print_env - prints current environment
 * @args: command line arguments
 * @envp: environment variables
 * @argv: current exe filename
 * @count: current counter
 * Return: int
 */
int print_env(char **args, char **envp, char *argv, int count)
{
	int i = 0;

	UNUSED(envp);
	UNUSED(argv);
	UNUSED(count);
	if (args[1] != NULL)
	{
		printf("env: '%s': No such file or directory\n", args[1]);
		return (1);
	}
	while (envp[i])
		printf("%s\n", envp[i++]);
	return (1);
}
