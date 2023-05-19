#include "main.h"
/**
 * handle_cd - handles the cd built in command
 * @args: command line argument
 * @envp: environment variables
 * @argv: current exe file
 * @count: current count
 *
 * Return: 0 (Success), 0 (Fail)
 */
int handle_cd(char **args, char **envp, char *argv, int count)
{
	char *dir = malloc(10), *oldpwd, cwd[1024], *use;
	int i, j, k;

	(void)envp;
	_strcpy(dir, args[1]);
	if (!getcwd(cwd, sizeof(cwd)))
		perror("Failed to get Path\n");
	oldpwd = malloc(sizeof(cwd));
	_strcpy(oldpwd, cwd);
	if (_strcmp(dir, ""))
	{
		dir = _getenv("HOME");
		i = chdir(dir);
	}
	else if (_strcmp(dir, "-"))
	{
		dir = _getenv("OLDPWD");
		_printf("%s\n", dir);
		i = chdir(dir);
	}
	else if (_strcmp(dir, "~"))
	{
		dir = _getenv("HOME");
		i = chdir(dir);
	}
	else
	{
		i = chdir(dir);
		use = _strcat(cwd, "/");
		dir = _strcat(use, dir);
	}
	if (i == -1)
	{
		_printf("%s: %d: cd: can't cd to %s\n", argv, count, args[1]);
		free(dir);
		return (1);
	}
	if (_strcmp(args[1], "..") || _strcmp(args[1], "."))
		j = _setenv2("PWD", getcwd(cwd, sizeof(cwd)), 1);
	else
		j = _setenv2("PWD", dir, 1);
	k = _setenv2("OLDPWD", oldpwd, 1);
	if (j == -1 || k == -1)
		_printf("Error\n");
	return (1);
}
