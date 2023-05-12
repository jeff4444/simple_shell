#include <stdio.h>
#include <string.h>
#include "test.h"
int main(int argc, char *argv[])
{
	size_t i = 0;
	char *s = NULL;
	int j = 0;
	char *token;

	argc = 0;
	printf("$ ");
	_getline(&s, &i, STDIN_FILENO);

	token = strtok(s, " ");
	while (token)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc++] = NULL;
	while (argv[j])
		printf("%s\n", argv[j++]);
	
	return (0);
}
