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
	int built, n = 0;

	(void)argc;
	while (1)
	{
		count++;
		if (!get_user_input(&read))
			break;
		args = tokenise_and_parse(read);
		if (args == NULL)
			continue;
		args = replace(args, &n);
		if (n == 100)
		{
			n = 0;
			continue;
		}
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
	char buf[1024];

	if (isatty(STDIN_FILENO))
		_puts("Jeff@");
		_puts(getenv("HOSTNAME"));
		_putchar(':');
		_puts(getcwd(buf, sizeof(buf)));
		_puts("$ ");
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
	int i;

	built_in built_ins[] = {
		{"exit", handle_exit}, {"env", print_env}, {"cd", handle_cd},
		{"setenv", _setenv}, {"unsetenv", _unsetenv}, {NULL, NULL}
	};

	for (i = 0; built_ins[i].name != NULL; i++)
		if (_strcmp(input, built_ins[i].name))
			return (built_ins[i].func(args, envp, argv, count));
	return (-1);
}
