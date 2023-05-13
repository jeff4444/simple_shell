#include "main.h"
/**
 * print_env - prints current environment
 * @envp: environment variables
 */
void print_env(char **envp)
{
	int i = 0;

	while (envp[i])
		printf("%s\n", envp[i++]);
}
