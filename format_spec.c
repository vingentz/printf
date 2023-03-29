#include "main.h"

/**
 * print_character - Prints a single character
 * @arg_list: list of arguments, containing the character to be printed
 * Return: Will return the number of characters printed (1)
 */
int print_character(va_list arg_list)
{
	_writechar(va_arg(arg_list, int));
	return (1);
}

/**
 * print_string - Prints a string
 * @arg_list: list of arguments, containing the string to be printed
 * Return: Will return the number of characters printed
 */
int print_string(va_list arg_list)
{
	int i;
	char *string;

	string = va_arg(arg_list, char *);
	if (string == NULL)
		string = "(null)";
	for (i = 0; string[i] != '\0'; i++)
		_writechar(string[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @arg_list: list of arguments, not used in this function
 * Return: will return the number of characters printed (1)
 */
int print_percent(__attribute__((unused))va_list arg_list)
{
	_writechar('%');
	return (1);
}

/**
 * print_integer - Prints an integer
 * @arg_list: list of arguments, containing the integer to be printed
 * Return: Will return the number of characters printed
 */
int print_integer(va_list arg_list)
{
	int num_length;

	num_length = print_s_int(arg_list);
	return (num_length);
}

/**
 * print_u_number - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_u_number(unsigned int n)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;
	num = n;

	for (; num / div > 9; )
		div *= 10
			;
	for (; div != 0; )
	{
		len += _writechar('0' + num / div);
		num %= div;
		div /= 10;
		}
	return (len);
}
