#include "main.h"

int _printf(const char *format, ...){
    
    int num_args = stringLen(format);

    va_list args;

    if (format == NULL){
        return (-1);
    }

    va_start(args,format);

	buffer = create_buffer();
	if (buffer == NULL)
		return (-1);

	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%') /* copy format into buffer until '%' */
		{
			len = check_buffer_overflow(buffer, len);
			buffer[len++] = format[i++];
			total_len++;
		}
		else /* if %, find function */
		{
			i++;
			if (format[i] == '\0') /* handle single ending % */
			{
				va_end(list);
				free(buffer);
				return (-1);
			}
			if (format[i] == '%') /* handle double %'s */
			{
				len = check_buffer_overflow(buffer, len);
				buffer[len++] = format[i];
				total_len++;
			}
			else
			{
				f = get_func(format[i]); /* grab function */
				if (f == NULL)  /* handle fake id */
				{
					len = check_buffer_overflow(buffer, len);
					buffer[len++] = '%'; total_len++;
					buffer[len++] = format[i]; total_len++;
				}
				else /* return string, copy to buffer */
				{
					str = f(list);
					if (str == NULL)
					{
						va_end(list);
						free(buffer);
						return (-1);
					}
					if (format[i] == 'c' && str[0] == '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = '\0';
						total_len++;
					}
					j = 0;
					while (str[j] != '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = str[j];
						total_len++; j++;
					}
					free(str);
				}
			} i++;
		}
	}
	write_buffer(buffer, len, list);
	return (total_len);
}

/**
 * starting space - creates initial space for the string until it's ready to print
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
 * print everything then set length 0 to start writing in the memory space again
 * @string: string to print
 * @len: position in memory
 * Return: length position
 */
int chk_space_overflow(char *string, int len)
{
	if (len > 1020)
	{
		write(1, string, len);
		len = 0;
	}
	return (len);
}