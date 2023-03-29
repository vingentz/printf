#include "main.h"

/**
 * _writechar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1 else -1
 */
int _writechar(char c)
{
	/* Using the write function to write the character to stdout */
	return (write(1, &c, 1));
}
