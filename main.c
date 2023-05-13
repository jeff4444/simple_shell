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
		built = handle_builtin_cmds(read, args, envp);
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
	n_chars = getline(input, &n, stdin);
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
 * Return: 1 (Found) -1 (Not found)
 */
int handle_builtin_cmds(char *input, char **args, char **envp)
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
			printf("Error! Exit status has to be a number\n");
			return (1);
		}
		exit(a);
	}
	else if (_strcmp(input, "env"))
	{
		print_env(envp);
		return (1);
	}
	return (-1);
}
