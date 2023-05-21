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
		_puts("env: '");
		_puts(args[1]);
		_puts("': No such file or directory\n");
		return (1);
	}
	while (envp[i])
		_puts(envp[i++]);
	return (1);
}
