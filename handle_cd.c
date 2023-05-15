#include "main.h"
/**
 * handle_cd - handles the cd built in command
 * @args: command line argument
 *
 * Return: 0 (Success), 0 (Fail)
 */
int handle_cd(char **args)
{
	char *dir = args[1], *backslash = malloc(2);
	int i;
	char cwd[1024];
	char *oldpwd;

	if (backslash == NULL)
	{
		perror("Error: Not enough space\n");
		return (0);
	}
	backslash[0] = '/';
	backslash[1] = '\0';
	if (!getcwd(cwd, sizeof(cwd)))
		perror("Failed to get Path\n");
	oldpwd = malloc(sizeof(cwd));
	strcpy(oldpwd, cwd);
	if (!dir)
	{
		dir = getenv("HOME");
		i = chdir(dir);
	}
	else if (_strcmp(dir, "-"))
	{
		dir = getenv("OLDPWD");
		i = chdir(dir);
	}
	else
	{
		i = chdir(dir);
		dir = strcat(backslash, dir);
		dir = strcat(cwd, dir);
	}

	if (i == -1)
		return (1);
	i = setenv("PWD", dir, 1);
	if (i == -1)
		printf("Error");
	i = setenv("OLDPWD", oldpwd, 1);
	if (i == -1)
		printf("Error");
	free(backslash);
	return (0);
}
