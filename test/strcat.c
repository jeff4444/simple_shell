#include "main.h"
char *_strcat(char *s1, char *s2)
{
	int len = strlen(s1) + strlen(s2) + 1;
	char *s = malloc(sizeof(char) * len);
	int i = 0, j = 0;

	while (s1[i] != '\0')
		s[i] = s1[i];
	while (s2[j] != '\0')
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
