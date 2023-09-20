#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 * _convert_binary - function that handle specifiers b;
 * @b: format b
 * @count: counter
 */
void _convert_binary(va_list b, int *count)
{
	unsigned int number, temp;
	int bitSize;
	char *binaryValue;
	int index, i;

	bitSize = 0;
	number = va_arg(b, unsigned int);
	temp = number;
	while (temp > 0)
	{
		bitSize++;
		temp /= 2;
	}
	binaryValue = (char *)malloc((bitSize + 1) * sizeof(int));
	binaryValue[bitSize] = '\0';
	index = bitSize - 1;
	while (number > 0)
	{
		binaryValue[index] = number % 2 + '0';
		number /= 2;
		index--;
	}
	for (i = 0; i < bitSize; i++)
	{
		_putchar(binaryValue[i]);
		(*count)++;
	}

	free(binaryValue);
}
/**
 * _pointer_spec - function to handle pointer specifiers
 * @p: format p
 * @count: counter
 */
void _pointer_spec(va_list p, int *count)
{
	char *hex_digits;
	char *nullValue;
	char buffer[16];
	int index, i;
	unsigned long int value;

	index = i = 0;
	va_arg(p, void *);
	if (va_arg(p, void *) != NULL)
	{
		_putchar('0');
		_putchar('x');
		value = (unsigned long int)va_arg(p, void*);
		if (value == 0)
		{
			_putchar('0');
		} else
		{
			hex_digits = "0123456789abcdef";
			while (value > 0)
			{
				buffer[index++] = hex_digits[value % 16];
				value /= 16;
			}
			for (i = index - 1; i >= 0; i--)
			{
				_putchar(buffer[i]);
				(*count)++;
			}
		}
	} else
	{
		nullValue = "(null)";
		while (*nullValue)
		{
			_putchar(*nullValue);
			nullValue++;
			(*count)++;
		}
	}
}
