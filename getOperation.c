#include "main.h"

/**
 * get_operation - outputs function for the key
 * @c: key for function
 * Return: Pointer to function
 */
char* (*get_operation(char c))(va_list)
{
	int k = 0;

	key_ops keys[] = {
		{'c', handle_c},
		{'s', handle_s}
	};

	while (keys[k].keyID != '\0')
	{
		if (keys[k].keyID == c)
        {
            return (keys[k].rule);
        }
		k++;
	}
	return (NULL);
}
