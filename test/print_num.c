#include "main.h"

/**
 * print_nums - prints an integer
 *
 * @n: integer input
 */
char *print_nums(int n)
{
	int pow, fact, tracker, i, j = 0;
	char *string;

	pow = 10;
	while ((pow * 10) <= n)
	{
		j++;
		pow *= 10;
	}
	string = malloc(j + 3);
	j = 0;
	while (n >= 10)
	{
		fact = n / pow;
		n -= (pow * fact);
		string[j] = (fact + '0');
		j++;
		if (n == 0)
		{
			tracker = 0;
			while (pow != 1)
			{
				pow /= 10;
				tracker++;
			}
			break;
		}
		pow /= 10;
	}
	if (n != 0)
	{
		string[j++] = (n + '0');
	}
	else
	{
		for (i = 0; i < tracker; i++)
		{
			string[j++] = '0';
		}
	}
	string[j] = '\0';
	return (string);
}

