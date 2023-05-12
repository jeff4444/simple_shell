#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	size_t i = 0;
	char *s = NULL;
	int j = 0;
	char *token;

	argc = 0;
	printf("$ ");
	getline(&s, &i, stdin);

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
