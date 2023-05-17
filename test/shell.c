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
	char *read = NULL, **args = NULL, *stringexe;
	pid_t i;
	int count = 0, swait;
	struct stat st;

	(void)argv;
	(void)argc;

	while (1)
	{
		count++;
		if (!get_user_input(&read))
			break;
		args = tokenise(read);
		if (args == NULL)
			continue;
		stringexe = fix_path(args[0]);
		if (stat(stringexe, &st) == -1)
		{
			/* error here */
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
	n_chars = getline(input, &n, stdin);
	if (n_chars == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 2);
		return (0);
	}
	return (1);
}
