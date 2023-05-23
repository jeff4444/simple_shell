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
	char* dir;
	UNUSED(envp);

    if (args[1] == NULL) {
        dir = _getenv("HOME");
    } else {
        dir = args[1];
    }

    if (chdir(dir) == -1) {
        perror("chdir");
		printf("%s: %d: cd: can't cd to %s\n", argv, count, args[1]);
        return (1);
    }

    return (0);
}
