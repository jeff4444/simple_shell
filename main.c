#include "main.h"
/**
 * main - shell
 * @argc: number of cmd line args
 * @argv: list of command line args
 * @envp: environment variables
 * Return: 0 (Success)
 */
int main(int argc, char *argv[], char **envp)
{
	char *read = NULL, **args = NULL, *stringexe;
	pid_t i;
	int swait, count = 0;
	struct stat st;
	int built;

	(void)argc;
	while (1)
	{
		count++;
		if (!get_user_input(&read))
			break;
		args = tokenise(read);
		if (args == NULL)
			continue;
		printf("Going in\n");
		fflush(stdout);
		built = handle_builtin_cmds(read, args, envp, argv[0], count);
		if (built == 1)
			continue;
		stringexe = fix_path(args[0]);
		if (stat(stringexe, &st) == -1)
		{
			printf("%s: %d: %s: not found\n", argv[0], count, read);
			continue;
		}
		i = fork();
		if (i == 0)
			execute_command(args, stringexe, envp);
		else
			wait(&swait);
	}
	free(read);
	if (args != NULL)
		free(args);
	return (0);
}


/**
 * get_user_input - gets input from user
 * @input: user input
 * Return: 1 (Success) 0 (Fail)
 */
int get_user_input(char **input)
{
	ssize_t n_chars;
	size_t n = 0;

	if (isatty(STDIN_FILENO))
		printf("Jeff$ ");
	n_chars = _getline(input, &n, stdin);
	if (n_chars == -1)
	{
		if (isatty(STDIN_FILENO))
			printf("\n");
		return (0);
	}
	return (1);
}

/**
 * handle_builtin_cmds - handles built in commands
 * @input: input
 * @args: command line arguments
 * @envp: environment variables
 * @argv: name of command used to run program
 * @count: how many times the program has run
 * Return: 1 (Found) -1 (Not found)
 */
int handle_builtin_cmds(char *input, char **args, char **envp,
		char *argv, int count)
{
	int a;
	char **endptr = NULL;

	if (_strcmp(input, "exit"))
	{
		if (_strcmp(input, "exit") && args[1] == NULL)
			exit(0);
		if (_strcmp(args[1], "0"))
			exit(0);
		a = strtod(args[1], endptr);
		if (a == 0)
		{
			printf("%s: %d: %s: Illegal number: %s\n", argv, count, input, args[1]);
			return (1);
		}
		exit(a);
	}
	else if (_strcmp(input, "env"))
	{
		if (args[1] != NULL)
		{
			printf("env: '%s': No such file or directory\n", args[1]);
			return (1);
		}
		print_env(envp);
		return (1);
	}
	else if (_strcmp(input, "cd"))
	{
		a = handle_cd(args);
		if (a)
			printf("%s: %d: cd: can't cd to %s\n", argv, count, args[1]);
		return (1);
	}
	return (-1);
}
