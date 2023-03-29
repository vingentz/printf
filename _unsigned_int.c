#include "main.h"

/**
 * print_s_int - prints an unsigned integer
 * @args: variadic function arguments
 * Return: value of the return type of the integer
 */
int print_s_int(va_list args)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _writechar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _writechar('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (len);
}

/**
 * print_unsigned_integer - Prints an unsigned integer
 * @arg_list: list of arguments
 * Return: The number of characters printed
 */

int print_unsigned_integer(va_list arg_list)
{
	unsigned int number;
	
	number = va_arg(arg_list, unsigned int);

	if (number == 0)
		return (print_u_number(number));
	if (number < 1)
		return (-1);
	return (print_u_number(number));
}
