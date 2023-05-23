#include "main.h"

/**
 * _puts - prints the text entered to the console
 * @str: text to be printed
 *
 * Return: void
*/
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - prints a character
 * @c: character to be printed
 *
 * Return: void
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
