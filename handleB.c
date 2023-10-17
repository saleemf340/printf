#include "main.h"
/**
 * int_to_bin - convert integer to binary
 * @args: integer to convert
 * Return: binary
 */
char *int_to_bin(va_list args)
{
	int a, b, c, t;
	char *s;

	a = 0;

	t = 1;

	c = va_arg(args, int);
	b = c;

	s = malloc(sizeof(char) * 33);
	if (s == NULL)
		return (NULL);


	if (c < 0)
	{
		s[0] = 1 + '0';
		a++;
		c *= -1;
		b *= -1;
	}

	while (c > 1)
	{
		c /= 2;
		t *= 2;
	}

	while (t > 0)
	{
		s[a++] = (b / t + '0');
		b %= t;
		t /= 2;
	}
	s[a] = '\0';

	return (s);
}
