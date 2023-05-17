#include "main.h"
/**
 * _strcmp - compares two string
 * @s1: string one
 * @s2: string two
 * Return: 1 (Same), 0 (Not same)
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i] != '\0')
		return (0);
	return (1);
}
