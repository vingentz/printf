#include "main.h"

/**
 * print_binary - prints the binary representation of an unsigned int
 * @list: va_list containing the number to be printed
 * Return: number of characters printed
 */
int print_binary(va_list list)
{
	unsigned int number;
	int index;
	int length;
	char *binary_str;
	char *reverse_str;

	number = va_arg(list, unsigned int);
	if (number == 0)
		return (_writechar('0'));
	if (number < 1)
		return (-1);
	length = base_length(number, 2);
	binary_str = malloc(sizeof(char) * length + 1);
	if (binary_str == NULL)
		return (-1);

	for (index = 0; number > 0; index++)
	{
		if (number % 2 == 0)
			binary_str[index] = '0';
		else
			binary_str[index] = '1';
		number = number / 2;
	}

	binary_str[index] = '\0';
	reverse_str = reverse_string(binary_str);
	if (reverse_str == NULL)
		return (-1);
	write_string(reverse_str);
	free(binary_str);
	free(reverse_str);
	return (length);
}

/**
 * print_octal - converts and prints an unsigned int as an octal number
 * @arg_list: va_list containing the unsigned int to convert and print
 * Return: length of the octal string
 */

int print_octal(va_list arg_list)
{
	unsigned int input_num;
	int length;
	char *octal_representation;
	char *reversed_str;

	input_num = va_arg(arg_list, unsigned int);

	/*check for invalid input */
	if (input_num == 0)
		return (_writechar('0'));
	if (input_num < 1)
		return (-1);
	/*get the length of the octal representation */
	length = base_length(input_num, 8);

	/*allocate memory for octal representation */
	octal_representation = malloc(sizeof(char) * length + 1);
	if (octal_representation == NULL)
		return (-1);
	/*convert input to octal representation */
	for (length = 0; input_num > 0; length++)
	{
		octal_representation[length] = (input_num % 8) + 48;
		input_num = input_num / 8;
	}

	octal_representation[length] = '\0';
	/*reverse the octal representation */
	reversed_str = reverse_string(octal_representation);
	if (reversed_str == NULL)
		return (-1);
	/*write the octal representation to the output */
	write_string(reversed_str);
	/*Free allocated memory*/
	free(octal_representation);
	free(reversed_str);

	/*Return the length of the octal representation*/
	return (length);
}
