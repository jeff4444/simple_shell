#include "main.h"
/**
 * fix_dir - fixes dir
 * @dir: dir
 * @cwd: cwd
 * Return: fixed dir
 */
char *fix_dir(char *dir, char *cwd)
{
	int j;

	j = _strlen(cwd);
	cwd[j] = '/';
	cwd[j + 1] = '\0';
	_strcpy(&(cwd[_strlen(cwd)]), dir);
	free(dir);
	dir = malloc(_strlen(cwd) + 1);
	_strcpy(dir, cwd);
	return (dir);
}

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
	char *dir, *oldpwd, cwd[1024], *new_dir;
	int i;

	(void)envp;
	if (args[1])
	{
		dir = malloc(_strlen(args[1]) + 1);
		_strcpy(dir, args[1]);
	}
	else
		dir = NULL;
	if (!getcwd(cwd, sizeof(cwd)))
		perror("Failed to get Path\n");
	oldpwd = malloc(sizeof(cwd));
	_strcpy(oldpwd, cwd);
	if (args[1] != NULL && !_strcmp(dir, "-") && !_strcmp(dir, "~"))
	{
		i = chdir(dir);
		dir = fix_dir(dir, cwd);
	}
	else
	{
		new_dir = _getdir(dir);
		i = chdir(new_dir);
		free(dir);
		dir = new_dir;
	}
	if (i == -1)
	{
		_printf("%s: %d: cd: can't cd to %s\n", argv, count, args[1]);
		return (1);
	}
	if (_strcmp(args[1], "..") || _strcmp(args[1], "."))
		_setenv2("PWD", getcwd(cwd, sizeof(cwd)), 1);
	else
		_setenv2("PWD", dir, 1);
	_setenv2("OLDPWD", oldpwd, 1);
	free(oldpwd);
	free(dir);
	return (1);
}

/**
 * _getdir - gets the dir depending on the input
 * @dir: dir
 * Return: dir
 */
char *_getdir(char *dir)
{
	char *d = NULL;

	if (dir == NULL)
	{
		d = malloc(_strlen(_getenv("HOME")) + 1);
		_strcpy(d, _getenv("HOME"));
	}
	else if (_strcmp(dir, "-"))
	{
		d = malloc(_strlen(_getenv("OLDPWD")) + 1);
		_strcpy(d, _getenv("OLDPWD"));
		_printf("%s\n", d);
	}
	return (d);
}
