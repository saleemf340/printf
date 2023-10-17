#include "main.h"

/**
 * get_operation - outputs function for the key
 * @c: key for function
 * Return: Pointer to function
 */
char* (*get_operation(char c))(va_list)
{
	int i = 0;

	key_ops identifier[] = {
		{'c', handle_c},
        {'d', handle_d},
        {'s', handle_s},
        {'i', handle_d},
        {'R', encrypt_rot13},
        {'b', int_to_bin},
        {'r', reverse},
        {'\0', NULL}
	};

	while (identifier[i].keyID != '\0')
	{
		if (identifier[i].keyID == c)
        {
            return (identifier[i].rule);
        }
		i++;
	}
	return (NULL);
}
