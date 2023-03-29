#include "main.h"

/**
 * _printf - Gets main string and parameters to print formatted string
 * @format: A string containing all the characters
 * Return: A total character count
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	/*list of functions for different format specifiers*/
	conver_t function_list[] = {
			{"c", print_character},
			{"s", print_string},
			{"%", print_percent},
			{"d", print_integer},
			{"i", print_integer},
			{"b", print_binary},
			{"r", print_reversed},
			{"R", rot13},
			{"u", print_unsigned_integer},
			{"o", print_octal},
			{"x", print_hex_lo},
			{"X", print_hex_cap},
			{NULL, NULL}
		};

	va_list arg_list;
	/*checking if format string is null*/
	if (format == NULL)
		return (-1);

	/*initializing the list of arguments*/
	va_start(arg_list, format);
	/*Calling parser function to parse the format string and arguments*/
	printed_chars = parser(format, function_list, arg_list);
	/*ending the list of arguments*/
	va_end(arg_list);
	return (printed_chars);
}
