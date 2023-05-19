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

	UNUSED(envp);
	strcpy(dir, args[1]);
	if (!getcwd(cwd, sizeof(cwd)))
		perror("Failed to get Path\n");
	oldpwd = malloc(sizeof(cwd));
	strcpy(oldpwd, cwd);
	if (_strcmp(dir, ""))
	{
		dir = getenv("HOME");
		i = chdir(dir);
	}
	else if (_strcmp(dir, "-"))
	{
		dir = getenv("OLDPWD");
		printf("%s\n", dir);
		i = chdir(dir);
	}
	else if (_strcmp(dir, "~"))
	{
		dir = getenv("HOME");
		i = chdir(dir);
	}
	else
	{
		i = chdir(dir);
		use = strcat(cwd, "/");
		dir = strcat(use, dir);
	}
	if (i == -1)
	{
		printf("%s: %d: cd: can't cd to %s\n", argv, count, args[1]);
		return (1);
	}
	if (_strcmp(args[1], "..") || _strcmp(args[1], "."))
		j = setenv("PWD", getcwd(cwd, sizeof(cwd)), 1);
	else
		j = setenv("PWD", dir, 1);
	k = setenv("OLDPWD", oldpwd, 1);
	if (j == -1 || k == -1)
		printf("Error");
	return (1);
// 	if (args[1] == NULL) {
//         fprintf(stderr, "Expected argument to \"cd\"\n");
//     } else {
//         if (chdir(args[1]) != 0) {
//             perror("chdir() failed");
//         }
//     }
//     return 1;
}
