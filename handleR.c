#include "main.h"
/**
 * reverse - reverses string
 * @list: string to be  reverse
 * Return: string in reverse
 */

char *reverse(va_list args)
{
	char *rog;
	char *og;
	int r, size, v;

	r = 0;

	og = va_arg(args, char *);
	if (og == NULL)
	{
		og = ")llun(";
	}
	size = stringLen(og);

	rog = malloc(sizeof(char) * (size + 1));
	if (rog == NULL)
	{
		return (NULL);
	}

	for (v = (size - 1); v >= 0; v--)
	{
		rog[r++] = og[v];
	}
	rog[r] = '\0';

	return (rog);
}
