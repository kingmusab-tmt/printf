#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 * _convert_binary - function that handle specifiers b;
 * @b: format b
 */
void _convert_binary(va_list b, int *count)
{
	unsigned int number, temp;
	int bitSize;
	char *binaryValue;
	int index;
	int i;

	bitSize = 0;
	number = va_arg(b, unsigned int);
	temp = number;
	while (number > 0)
	{
		bitSize++;
		number /= 2;
	}
	binaryValue = (char *)malloc(bitSize * sizeof(int));
	binaryValue[bitSize] = '\0';
	index = bitSize - 1;
	while (temp > 0)
	{
		binaryValue[index] = temp % 2 + '0';
		temp /= 2;
		index--;
	}

	for (i = 0; i < bitSize; i++)
	{
		_putchar(binaryValue[i]);
		(*count)++
	}
	free(binaryValue);
}
/**
 * _pointer_spec - function to handle pointer specifiers
 * @p: format p
 */
void _pointer_spec(va_list p, int *count)
{
	void *hexaValue;
	int i = 0;
	char *hex_digits;
	char buffer[16];
	int index;
	char *nullValue;
	unsigned long int value;

	hexaValue = va_arg(p, void *);
	if (hexaValue != NULL)
	{
		_putchar('0');
		_putchar('x');

		value = (unsigned long int)hexaValue;
		if (value == 0)
		{
			_putchar('0');
		} else
		{
			hex_digits = "0123456789abcdef";

			index = 0;

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
