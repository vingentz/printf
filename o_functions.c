#include "main.h"

/**
 * reverse_string - reverses the order of characters in a string
 * @original_string: string to be reversed
 * Return: a pointer to the reversed string on success, NULL on failure
 */
char *reverse_string(char *original_string)
{
	int length;
	int front;
	char temp;
	char *reversed_string;

	for (length = 0; original_string[length] != '\0'; length++)
	{}

	reversed_string = malloc(sizeof(char) * length + 1);
	if (reversed_string == NULL)
		return (NULL);

	memory_copy(reversed_string, original_string, length);
	for (front = 0; front < length; front++, length--)
	{
		temp = reversed_string[length - 1];
		reversed_string[length - 1] = reversed_string[front];
		reversed_string[front] = temp;
	}
	return (reversed_string);
}
/**
 * write_string - writes a string to the output
 * @input_string: string to be written
 */
void write_string(char *input_string)
{
	int index;

	for (index = 0; input_string[index] != '\0'; index++)
	{
		_writechar(input_string[index]);
	}
}
/**
 * base_length - calculates the number of digits in a
 * given number when represented in a specific base
 * @number: number to be calculated
 * @base: base of the representation
 * Return: the number of digits
 */
unsigned int base_length(unsigned int number, int base)
{
	unsigned int counter;

	for (counter = 0; number > 0; counter++)
	{
		number = number / base;
	}
	return (counter);
}
/**
 * memory_copy - copies n bytes from memory area src to memory area dest
 * @destination: pointer to the destination memory area
 * @source: pointer to the source memory area
 * @num_bytes: number of bytes to be copied
 * Return: pointer to the destination memory area
 */
char *memory_copy(char *destination, char *source, unsigned int num_bytes)
{
	unsigned int index;

	for (index = 0; index < num_bytes; index++)
	{
		destination[index] = source[index];
	}
	destination[index] = '\0';
	return (destination);
}
