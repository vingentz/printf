#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


/**
 * struct conversion_specifier - contains two fields: symbol, a string that represents a specific conversion specifier
 * and func a pointer to a function that takes in a va_list as an
 * argument and handles the corresponding conversion specifier.
 * The struct is then given an alias conver_t for easier
 * reference throughout the rest of the code.
 * @symbol: A string containing the symbol that represents a specific conversion specifier
 * (e.g. 'c' for character, 's' for string, etc.)
 * @func: A pointer to a function that takes in a va_list
 * as an argument and handles the corresponding conversion specifier
 */
struct conversion_specifier
{
		char *symbol;
			int (*func)(va_list);
};

/* Define an alias for the struct conversion_specifier */
typedef struct conversion_specifier conver_t;

/**
 * _printf - function that produces output according to a format
 * @format: string that contains the text to be written to stdout
 * Return: the number of characters printed
 */
int _printf(const char *format, ...);

/**
 * _writechar - function that writes a character to stdout
 * @c: character to be written to stdout
 * Return: the number of characters printed (1 for success, -1 for failure)
 */
int _writechar(char c);

/**
 * parser - function that parses the format string and
 * calls the appropriate conversion function
 * @main_string: format string to be parsed
 * @function_list: array of conversion functions
 * @arg_list: variable argument list
 * Return: the number of characters printed
 */
int parser(const char *main_string, conver_t function_list[], va_list arg_list);

/**
 * print_character - function that prints a single character
 * @arg_list: variable argument list
 * Return: the number of characters printed
 */
int print_character(va_list arg_list);

/**
 * print_string - function that prints a string
 * @arg_list: variable argument list
 * Return: the number of characters printed
 */
int print_string(va_list arg_list);

/**
 * print_percent - function that prints a percent sign
 * @arg_list: variable argument list
 * Return: the number of characters printed
 */
int print_percent(__attribute__((unused))va_list arg_list);

/**
 * print_integer - function that prints an integer
 * @arg_list: variable argument list
 * Return: the number of characters printed
 */
int print_integer(va_list arg_list);

/**
 * print_u_number - function that prints an unsigned number
 * @n: the number to be printed
 * Return: the number of characters printed
 */
int print_u_number(unsigned int n);

/**
 * print_s_int - function that prints an integer in signed format
 * @args: variable argument list
 * Return: the number of characters printed
 */
int print_s_int(va_list args);

/**
 * print_unsigned_integer - function that prints an unsigned integer
 * @arg_list: variable argument list
 * Return: the number of characters printed
 */
int print_unsigned_integer(va_list arg_list);

/**
 * print_reversed - function that prints a string in reverse
 * @arg: variable argument list
 * Return: the number of characters printed
 */
int print_reversed(va_list arg);

/**
 * _isalpha - function that checks if a character is alphabetic
 * @c: character to be checked
 * Return: 1 if alphabetic, 0 if not
 */
int _isalpha(char c);

/**
 * rot13 - function that applies the ROT13 encryption to a string
 * @list: variable argument list
 * Return: the number of characters printed
 */
int rot13(va_list list);

/**
 * reverse_string - function that reverses the order of characters in a string
 * @original_string: string to be reversed
 * Return: the reversed string
 */
char *reverse_string(char *original_string);

/**
 * write_string - function that writes a string to stdout
 * @input_string: string to be written to stdout
 */
void write_string(char *input_string);

/**
 * base_length - function that
 * calculates the number
 * of digits in a number in a given base
 * @number: number to be checked
 * @base: base to be used in the calculation
 * Return: the number of digits in the number in the given base
 */
unsigned int base_length(unsigned int number, int base);

/**
 * memory_copy - function that copies a specified number
 * of bytes from one memory location to another
 * @destination: destination memory location
 * @source: source memory location
 * @num_bytes: number of bytes to be copied
 * Return: pointer to the destination memory location
 */
char *memory_copy(char *destination, char *source, unsigned int num_bytes);

/**
 * print_binary - function that prints a number in binary format
 * @list: variable argument list
 * Return: the number of characters printed
 */
int print_binary(va_list list);

/**
 * print_octal - function that prints a number in octal format
 * @arg_list: variable argument list
 * Return: the number of characters printed
 */
int print_octal(va_list arg_list);

/**
 * hex_check - function that checks if a number is greater than or equal to 10
 * @number: number to be checked
 * @letter: letter to be printed
 * Return: the number of characters printed
 */
int hex_check(int number, char letter);
/**
 * print_hex_cap - function that prints a number
 * in uppercase hexadecimal format
 * @list: variable argument list
 * Return: the number of characters printed
 */
int print_hex_cap(va_list list);

/**
 * print_hex_lo - function that prints a number in lowercase hexadecimal format
 * @arg_list: variable argument list
 * Return: the number of characters printed
 */
int print_hex_lo(va_list arg_list);

#endif
