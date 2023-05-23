#include "main.h"
/**
 * _strlen - returns string length
 * @s: string input
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len;

	len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
