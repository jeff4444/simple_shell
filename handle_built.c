#include "main.h"
/**
 * handle_built - handles built in commands
 * @args: list of command line args
 * @envp: environment variables
 * @argv: contains name of run file
 * @count: count
 * Return: 1 (found) 0 (not found)
 */
int handle_built(char **args, char **envp, char **argv, int count,
		char **reads, char *read)
{

	if (_strcmp(args[0], "exit"))
	{
		handle_exit(args, argv, envp, count, reads, read);
		return (1);
	}
	else if (_strcmp(args[0], "setenv"))
	{
		_setenv(args, envp, argv[0], count);
		return (1);
	}
	else if (_strcmp(args[0], "unsetenv"))
	{
		_unsetenv(args, envp, argv[0], count);
		return (1);
	}
	else if (_strcmp(args[0], "cd"))
	{
		handle_cd(args, envp, argv[0], count);
		return (1);
	}
	else if (_strcmp(args[0], "env"))
	{
		print_env(args, envp, argv);
		return (1);
	}
	return (0);
}
