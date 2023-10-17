#include "main.h"
/**
 * rot13 - encrypts with rot13 standard
 * @args: string to change
 * Return: encrypted version of input
 */
char *encrypt_rot13(va_list args)
{
	int e = 0;
	char *og;
	char *enc;

	og = va_arg(args, char *);

    /* memory for encrypted characters*/
	enc = malloc(sizeof(char) * (_strlen(og) + 1));

	if (enc == NULL)
	{
		return (NULL);
	}

	/* og chars to enc encrypted chars*/
	while (og[e] != '\0')
	{
		if ((og[e] >= 'a' && og[e] <= 'm') || (og[e] >= 'A' && og[e] <= 'M'))
		{
			enc[e] = og[e] + 13;
		}
		else if ((og[e] >= 'n' && og[e] <= 'z') || (og[e] >= 'N' && og[e] <= 'Z'))
		{
			enc[e] = og[e] - 13;
		}
		else
			(enc[e] = og[e]);
		e++;
	}
	enc[e] = '\0';

	return (enc);
}
