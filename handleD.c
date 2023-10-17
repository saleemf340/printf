#include "main.h"
/**
 * handle_d - gets length to put in int_to_str
 * @args: takes arguments
 * Return: integer as a string
 **/
char *handle_d(va_list args)
{
	int len_size, multiple, d, tmpry;

	d = va_arg(args, int);
	tmpry = d;
	len_size = 0;
	multiple = 1;

	if (d == 0)
	{
		len_size++;
		return (int_to_str(div, len_size, d));
	}

	while (tmpry != 0)
	{
		len_size += 1;
		if (len_size > 1)
			multiple *= 10;
		tmpry /= 10;
	}

	return (int_to_str(div, len_size, d));
}