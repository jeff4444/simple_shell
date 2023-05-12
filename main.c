#include "main.h"
/**
 * main - shell
 *
 * Return: 0 (Success)
 */
int main(void)
{
	char *read = NULL, **args = NULL, *stringexe;
	size_t n = 0;
	ssize_t n_chars = 0;
	pid_t i;
	int swait;
	struct stat st;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("Jeff$ ");
		n_chars = getline(&read, &n, stdin);
		if (n_chars == -1)
		{
			printf("\n");
			return (1);
		}
		if (_strcmp(read, "exit\n") || _strcmp(read, "env\n"))
		{
			if (_strcmp(read, "exit\n"))
				break;
			print_env();
			continue;
		}
		args = tokenise(read);
		stringexe = fix_path(args[0]);
		if (stat(stringexe, &st) == -1)
		{
			printf("%s: 1: %s: not found\n", args[0], read);
			continue;
		}
		i = fork();
		if (i == 0)
			execute_command(args, stringexe);
		else
			wait(&swait);
	}
	free(read);
	if (args != NULL)
		free(args);
	return (0);
}
