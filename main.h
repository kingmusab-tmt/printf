#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#define BUFFER_SIZE 1024
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
void _convert_binary(va_list b);
void _pointer_spec(va_list p);

#endif
