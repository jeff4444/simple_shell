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

	(void)envp;
	if (args[1] != NULL)
	{
		perror(argv[0]);
		return (1);
	}
	while (environ[i])
	{
		_printf("%s\n", environ[i]);
		i++;
	}
	printf("%s\n", _getenv("OLDPWD"));
	return (1);
}
