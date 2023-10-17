#include "main.h"

/**
 * handle_c - returns char as string
 * @list: char
 * Return: String verion of char
 */
char *handle_c(va_list list){
	char *mem;
	char c;

	c = va_arg(list, int);

	if (c == 0)
		c = '\0';

	mem = malloc(sizeof(char) * 2);
	if (mem == NULL)
		return (NULL);
	mem[0] = c;
	mem[1] = '\0';

	return (mem);
}