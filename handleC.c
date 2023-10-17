#include "main.h"

/**
 * handle_c - outputs char as string
 * @args: char
 * Return: String verion of char
 */
char *handle_c(va_list args){
	char *mem;
	char c;

	c = va_arg(args, int);

	if (c == 0)
		c = '\0';

	mem = malloc(sizeof(char) * 2);
	if (mem == NULL)
		return (NULL);
	mem[0] = c;
	mem[1] = '\0';

	return (mem);
}
