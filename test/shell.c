#include "main.h"
/**
 * main - shell
 * @argc: number of cmd line arguments
 * @argv: list of command line arguments
 * @envp: environment variables
 * Return: 0 (Success)
 */
int main(int argc, char *argv[], char **envp)
{
	char *read = NULL, **args, *stringexe;
	pid_t i;
	int count = 0, swait;
	struct stat st;

	(void)argc;

	while (1)
	{
		count++;
		args = NULL;
		if (!get_user_input(&read))
			break;
		args = tokenise(read);
		if (args == NULL)
			continue;
		if (handle_built(args, envp, argv, count))
		{
			free_args(args);
			continue;
		}
		stringexe = fix_path(args[0]);
		if (stat(stringexe, &st) == -1)
		{
			_printf("%s: %d: %s: not found\n", argv[0], count, args[0]);
			free_args(args);
			continue;
		}
		i = fork();
		if (i == 0)
			execute_command(args, stringexe, envp, argv);
		else
		{
			wait(&swait);
			free_args(args);
			free(stringexe);
		}
	}
	free(read);
	return (0);
}

/**
 * get_user_input - gets user input
 * @input: user input
 * Return: 1 (Success) 0 (Fail)
 */
int get_user_input(char **input)
{
	ssize_t n_chars;
	size_t n = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 3);
	n_chars = _getline(input, &n, STDIN_FILENO);
	if (n_chars == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 2);
		return (0);
	}
	return (1);
}

/**
 * handle_built - handles built in commands
 * @args: list of command line args
 * @envp: environment variables
 * @argv: contains name of run file
 * @count: count
 * Return: 1 (found) 0 (not found)
 */
int handle_built(char **args, char **envp, char **argv, int count)
{

	if (_strcmp(args[0], "exit"))
	{
		handle_exit(args, argv, envp, count);
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

/**
 * free_args - free args
 * @args: args
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args[i]);
	free(args);
}

