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

/**
 * _printf - prints a formatted string
 * @format: formatted string
 *
 * Return: length og format
 */
int _printf(const char *format, ...)
{
	int i;
	va_list args;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
			{
				_putchar(va_arg(args, int) + '0');
				i++;
			}
			else if (format[i] == 's')
			{
				_puts(va_arg(args, char *));
				i++;
			}
		}
		else
		{
			_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (i);
}
