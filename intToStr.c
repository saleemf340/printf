#include "main.h"

/**
 * int_to_str - converts int to string
 * @multiple: multiple of 10
 * @len_size: length of number
 * @num: number to convert to string
 * Return: string
 **/
char *int_to_str(int multiple, int len_size, int num)
{
	char *chr;
	int k = 0;

	chr = malloc(sizeof(char) * len_size + 1);
	if (chr == NULL)
		return (NULL);

	if (num < 0)
	{
		chr[0] = '-';
		k++;
	}
	while (num < 0)
	{
		chr[k] = ((num / multiple) * -1 + '0');
		num = num % multiple;
		multiple /= 10;
		k++;
	}
	while (multiple >= 1)
	{
		chr[k] = ((num / multiple) + '0');
		num = num % multiple;
		multiple /= 10;
		k++;
	}
	chr[k] = '\0';
	return (chr);
}