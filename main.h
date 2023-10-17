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
} key_ops ;

char *starting_space(void);
void print_to_screen(char *space, int len);
int chk_space_overflow(char *string, int len);

char *handle_c(va_list args);
char *handle_s(va_list args);
char *handle_d(va_list args);

char* (*get_operation(char c))(va_list);
char *int_to_str(int multiple, int len_size, int num);
char *int_to_bin(va_list args);

#endif
