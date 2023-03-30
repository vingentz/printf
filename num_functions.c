#include "main.h"

/**
 * print_hex_lo - takes in an unsigned int from a va_list
 * and converts it to its
 * hexadecimal representation. It then writes the hexadecimal representation to
 * stdout.
 * @arg_list: List name of arguments of the current function
 *
 * @arg_list: va_list containing the unsigned int to be converted
 * Return: length of the hexadecimal representation on success, -1 on failure
 */
int print_hex_lo(va_list arg_list)
{
	unsigned int decimal_num;
	int len;
	int remainder;
	char *hex_representation;
	char *reversed_hex;

	decimal_num = va_arg(arg_list, unsigned int);
	if (decimal_num == 0)
	{
		return (_writechar('0'));

	}

	if (decimal_num < 1)
	{
		return (-1);
	}
	len = base_length(decimal_num, 16);
	hex_representation = malloc(sizeof(char) * len + 1);
	if (hex_representation == NULL)
	{
		return (-1);
	}
	for (len = 0; decimal_num > 0; len++)
	{
		remainder = decimal_num % 16;
		if (remainder > 9)
		{
			remainder = hex_check(remainder, 'x');
			hex_representation[len] = remainder;
		}
		else
		{
			hex_representation[len] = remainder + 48;
		}

		decimal_num = decimal_num / 16;
	}
	hex_representation[len] = '\0';
	reversed_hex = reverse_string(hex_representation);
	if
		(reversed_hex == NULL)
		{
			return (-1);
		}
	write_string(reversed_hex);
	free(hex_representation);
	free(reversed_hex);
	return (len);
}
/**
 * print_hex_cap - converts the first argument of the va_list
 * to an uppercase hexadecimal representation
 * and writes it to the standard output
 * @list: va_list containing the argument to be converted
 *
 * Return: the length of the hexadecimal representation
 * -1 if the decimal number is less than 1
 * -1 if memory allocation fails
 */

int print_hex_cap(va_list list)
{
	unsigned int decimal_num;
	int rep_len;
	int remainder;
	char *hex_rep;
	char *reversed_hex;

	decimal_num = va_arg(list, unsigned int);
	if (decimal_num == 0)
		return (_writechar('0'));
	if (decimal_num < 1)
		return (-1);
	rep_len = base_length(decimal_num, 16);
	hex_rep = malloc(sizeof(char) * rep_len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (rep_len = 0; decimal_num > 0; rep_len++)
	{
		remainder = decimal_num % 16;
		if (remainder > 9)
		{
			remainder = hex_check(remainder, 'X');
			hex_rep[rep_len] = remainder;
		}
		else
		{ /*convert the remainder to its corresponding ASCII character*/
			hex_rep[rep_len] = remainder + 48;
		}
		decimal_num = decimal_num / 16;
	}
	hex_rep[rep_len] = '\0';
	reversed_hex = reverse_string(hex_rep);
	if (reversed_hex == NULL)
		return (-1);
	write_string(reversed_hex);
	free(hex_rep);
	free(reversed_hex);
	return (rep_len);
}
/**
 * hex_check - Check which hex functionis calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */

int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
