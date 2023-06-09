#include "main.h"
/**
 * handle_exit - handles the exit command
 * @args: command line args
 * @envp: environment variables
 * @av: command used to run file
 * @count: current count
 * @reads: reads
 * @read: read
 * Return: int
 */
int handle_exit(char **args, char **av, char **envp, int count,
		char **reads, char *read)
{
	int a, child_stat;
	pid_t child;

	(void)envp;
	if (args[1] == NULL || _strcmp(args[1], "0"))
	{
		free_args(args);
		free(read);
		free_args(reads);
		exit(0);
	}
	a = _atoi(args[1]);
	if (a <= 0)
	{
		child = fork();
		if (child == 0)
		{
			print_exit_error(av[0], count, args[1]);
			free_args(args);
			free_args(reads);
			free(read);
			exit(2);
		}
		else
		{
			waitpid(child, &child_stat, 0);
			if (WIFEXITED(child_stat))
				WEXITSTATUS(child_stat);
			return (0);
		}
	}
	free_args(reads);
	free(read);
	free_args(args);
	exit(a);
}

/**
 * print_exit_error - prints exit error
 * @av: name of file
 * @count: count
 * @status: exit status
 */
void print_exit_error(char *av, int count, char *status)
{
	_puts(av);
	_puts(": ");
	_putchar(count + '0');
	_puts(": exit: Illegal number: ");
	_puts(status);
	_putchar('\n');
}
