#include "main.h"
#include "stdarg.h"
/**
 * p_char - function to print character
 * @c: character to be printed
 */
void p_char(va_list c)
{
	char  character;

	character = va_arg(c, int);
	_putchar(character);
}
/**
 * p_per - function to print unused format
 * @p: percent
 */
void p_per(va_list p)
{
	(void)p;

	_putchar('%');
}
/**
 * p_string - function for printing string
 * @s: string character to be printed
 */
void p_string(va_list s)
{
	char *string;

	string = va_arg(s, char*);
	if (string)
	{
		while (*string)
		{
			_putchar(*string);
			string++;
		}
	} else
	{
		_putchar('N');
		_putchar('U');
		_putchar('L');
		_putchar('L');
	}
}
/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: the number of characters printed exluding the null byte
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	count = 0;
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			count += (*format == 'c') ? (p_char(ap), 1) :
				(*format == 's') ? (p_string(ap), 1) :
				(*format == '%') ? (p_per(ap), 1) :
				(*format == 'b') ? (_convert_binary(ap), 1) :
				(*format == 'p') ? (_pointer_spec(ap), 1) :
				(_putchar('%'), _putchar(*format), 2);
		} else
		{
			 _putchar(*format);
			 count++;
		}
		format++;
	}

	va_end(ap);
	return (count);
}
