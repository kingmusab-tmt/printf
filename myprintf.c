#include "main.h"
#include "stdarg.h"
#include "stdio.h"
/**
 * p_char - function to print character
 * @c: character to be printed
 * @count: count character
 */
void p_char(va_list c, int *count)
{
	char  character;

	character = va_arg(c, int);
	_putchar(character);
	(*count)++;
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
 * @count: count character
 */
void p_string(va_list s, int *count)
{
	char *string;
	char *nullString;

	string = va_arg(s, char*);
	if (string)
	{
		while (*string)
		{
			_putchar(*string);
			string++;
			(*count)++;
		}
	} else
	{
		nullString = "(null)";
		while (*nullString)
		{
			_putchar(*nullString);
			nullString++;
			(*count)++;
		}
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
	if (format == NULL)
	{
		return (-1);
	}
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				_putchar('%');
				count++;
			}
			count += (*format == 'c') ? (p_char(ap, &count), 0) :
				(*format == 's') ? (p_string(ap, &count), 0) :
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
