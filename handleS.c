#include "main.h"
/**
 * handle_s - input string output string
 * @args: string
 * Return: string
 */
char *handle_s(va_list args)
{
	char *source;
	char *final;
	int len;

	source = va_arg(args, char *);
	if (source == NULL)
	{
		source = "(null)";
	}
	len = stringLen(source);
	final = malloc(sizeof(char) * len + 1);

	if (final == NULL)
	{
		return (NULL);
	}
		int x = 0;

	while (source[x] != '\0')
	{
		final[x] = source[x];
		x++;
	}

	final[x] = source[x];

	return (final);
}
