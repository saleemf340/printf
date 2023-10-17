#include "main.h"
/**
 * handle_s - takes string and return string
 * @list: string
 * Return: string
 */
char *handle_s(va_list list){
	char *source;
	char *final;
	int len;

	source = va_arg(list, char *);
	if (source == NULL)
		source = "(null)";

	len = _strlen(source);

	final = malloc(sizeof(char) * len + 1);
	if (final == NULL)
		return (NULL);
    
    int x = 0;

	while (source[x] != '\0')
	{
		final[x] = source[x];
		x++;
	}

	final[x] = source[x];

	return (final);
}