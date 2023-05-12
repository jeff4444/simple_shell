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
			return (1);
		if (_strcmp(read, "exit\n"))
		{
			printf("Shutting down...\n");
			sleep(1);
			break;
		}
		args = tokenise(read);
		stringexe = fix_path(args[0]);
		if (stat(stringexe, &st) == -1)
		{
			printf("Error! File not found\n");
			continue;
		}
		i = fork();
		if (i == 0)
			execute_command(args, stringexe);
		else
			wait(&swait);
	}

	free(read);
	if (args == NULL)
		return (0);
	free(args);
	return (0);
}
