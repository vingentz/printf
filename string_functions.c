#include "main.h"

/**
 * print_reversed - prints a reversed string passed in as an argument
 * @arg: variable argument list containing the
 * string to be reversed and printed
 * Return: the length of the reversed string on success, -1 on failure
 */
int print_reversed(va_list arg)
{
	int length;
	char *original_string;
	char *reversed_string;

	original_string = va_arg(arg, char *);
	/*check if the string passed in is valid*/
	if (original_string == NULL)
		return (-1);
	reversed_string = reverse_string(original_string);
	/*check if the reversed string is valid*/
	if (reversed_string == NULL)
		return (-1);
	for (length = 0; reversed_string[length] != '\0'; length++)
	/*write the reversed string to stdout*/
		_writechar(reversed_string[length]);
	free(reversed_string);
	return (length);
}
/**
 * _isalpha - checks if a character is an alphabet or not
 * @c: character to be checked
 * Return: 1 if the character is an alphabet, 0 otherwise
 */
int _isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * rot13 - applies ROT13 encryption to a string passed in as an argument
 * @list: variable argument list containing the string to be encrypted
 * Return: the length of the encrypted string on success, -1 on failure
 */
int rot13(va_list list)
{
	int index;
	char *original_string;

	original_string = va_arg(list, char *);

	if (original_string == NULL)
		return (-1);
	for (index = 0; original_string[index] != '\0'; index++)
	{
		if (_isalpha(original_string[index]))
		{
			if ((original_string[index] >= 'a' && original_string[index] <= 'm') ||
					(original_string[index] >= 'A' && original_string[index] <= 'M'))
				_writechar(original_string[index] + 13);
			else
				_writechar(original_string[index] - 13);
		}
		else
			_writechar(original_string[index]);
	}
	return (index);
}
