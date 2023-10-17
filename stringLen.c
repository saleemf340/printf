#include "main.h"
/**
 * stringLen - find length of string
 * @c: string passed to function
 * Return: integer length
 */
int stringLen(char *c)
{
	int a = 0;

	while (*(c + a))
	{
		a++;
	}
	return (a);
}
