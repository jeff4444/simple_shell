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
	char *read = NULL, *token, **reads, *read_copy;
	int count = 0, i;

	(void)argc;
	while (1)
	{
		i = 0;
		count++;
		if (!get_user_input(&read))
			break;
		read_copy = malloc(_strlen(read) + 1);
		_strcpy(read_copy, read);
		token = _strtok(read_copy, ";");
		while (token)
		{
			i++;
			token = _strtok(NULL, ";");
		}
		reads = malloc((i + 1) * sizeof(char *));
		token = _strtok(read, ";");
		i = 0;
		while (token)
		{
			reads[i] = malloc(_strlen(token) + 1);
			_strcpy(reads[i++], token);
			token = _strtok(NULL, ";");
		}
		reads[i] = NULL;
		i = 0;
		free(read_copy);
		free(token);
		while (reads[i])
		{
			execute_read(reads[i], envp, argv, count, reads, read);
			i++;
		}
		free_args(reads);
	}
	free(read);
	return (0);
}


/**
 * execute_read - executes a command
 * @read: read input
 * @envp: environment variables
 * @argv: list of cmd line args
 * @count: count
 * @reads: reads
 * @reader: reader
 * Return: 0
 */
int execute_read(char *read, char **envp, char **argv, int count,
		char **reads, char *reader)
{
	char **args = NULL, *stringexe;
	pid_t i;
	struct stat st;
	int swait;

	args = tokenise(read);
	if (args == NULL)
		return (0);
	args = replace(args);
	if (handle_built(args, envp, argv, count, reads, reader))
	{
		free_args(args);
		return (0);
	}
	stringexe = fix_path(args[0]);
	if (stat(stringexe, &st) == -1)
	{
		/* perror(argv[0]); */
		command_not_found(argv[0], count, args[0]);
		free_args(args);
		return (0);
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
	return (0);
}

/**
 * command_not_found - prints command not found
 * @arg: name of run file
 * @count: count
 * @name: name of error
 */
void command_not_found(char *arg, int count, char *name)
{
	_puts(arg);
	_puts(": ");
	_putchar(count + '0');
	_puts(": ");
	_puts(name);
	_puts(": not found\n");
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
		write(STDOUT_FILENO, "$ ", 2);
	n_chars = _getline(input, &n, STDIN_FILENO);
	if (n_chars == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	return (1);
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

