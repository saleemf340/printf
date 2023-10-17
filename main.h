#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int stringLen(char *c);

typedef struct Key
{
	char keyID;
	char* (*rule)(va_list);
} print;

#endif