#include "main.h"
/**
 * print_env - prints current environment
 */
extern char **environ;
void print_env(void)
{
	int i = 0;

	while (environ[i])
		printf("%s\n", environ[i++]);
}
