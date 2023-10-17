#include "main.h"

/**
 * get_func - returns needed function
 * @i: identifier for function
 * Return: Pointer to needed function
 */
char (*get_operation(char i))(va_list)
{
	int k = 0;

	key_ops keys[] = {
		{'c', handle_c},
		{'s', handle_s}
	};

	while (keys[k].keyID != '\0')
	{
		if (keys[k].keyID == i)
			return (keys[k].rule);
		k++;
	}
	return (NULL);
}