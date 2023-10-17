#include "main.h"

/**
 * _printf - self made printf function
 * @format: initial string with all identifiers
 * Return: strings with keys substituated for variables
 */
int _printf(const char *format, ...)
{
	char *pos, *string;
	int size = 0, total_size = 0, p = 0, l = 0;
	char (*operation)(va_list);

	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	pos = starting_space();
	if (pos == NULL)
		return (-1);

	while (format[p] != '\0')
	{
		if (format[p] != '%') /* read format till a % is found */
		{
			size = chk_space_overflow(pos, size);
			pos[size++] = format[p++];
			total_size++;
		}
		else /* if %, find function */
		{
			p++;
			if (format[p] == '\0') /* single % */
			{
				va_end(args);
				free(pos);
				return (-1);
			}
			if (format[p] == '%') /* double %'s */
			{
				size = chk_space_overflow(pos, size);
				pos[size++] = format[p];
				total_size++;
			}
			else
			{
				operation = get_operation(format[p]); /* get relevant operation */
				if (operation == NULL)  /* empty id */
				{
					size = chk_space_overflow(pos, size);
					pos[size++] = '%';
					total_size++;
					pos[size++] = format[p];
					total_size++;
				}
				else
				{
					string = operation(args);

					if (string == NULL)
					{
						va_end(args);
						free(pos);
						return (-1);
					}

					if (format[p] == 'c' && string[0] == '\0')
					{
						size = chk_space_overflow(pos, size);
						pos[size++] = '\0';
						total_size++;
					}

					l = 0;

					while (string[l] != '\0')
					{
						size = chk_space_overflow(pos, size);
						pos[size++] = string[l];
						total_size++;
						l++;
					}

					free(string);
				}
			} p++;
		}
	}
	print_to_screen(pos, size);
	va_end(args);
	return (total_size);
}

/**
 * starting space - creates initial space for the string
 * Return: pointer to space created in memory
 */
char *starting_space(void)
{
	char *space;

	space = malloc(sizeof(char) * 1024);
	if (space == NULL)
		return (NULL);
	return (space);
}

/**
 * print_to_screen - prints whats in memory, then frees the memory
 * @space: space holding print-ables
 * @len: length of string
 */
void print_to_screen(char *space, int len)
{
	char *real_space;

	real_space = realloc(space, len); /* realloc to correct size */
	write(1, real_space, len); /* print */

	free(real_space);
}

/**
 * chk_space_overflow - if writing over allocated space,
 * print everything then set length 0 to start overwriting in the memory space
 * @string: string to print
 * @len: position in memory
 * Return: length position
 */
int chk_space_overflow(char *string, int len)
{
	if (len > 1024)
	{
		write(1, string, len);
		len = 0;
	}
	return (len);
}
