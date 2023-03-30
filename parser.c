#include "main.h"
/**
 * parser - Receives main string and necessary parameters to print string
 * @main_string: A string containing all the desired characters.
 * @function_list: A list of all the possible functions.
 * @arg_list: A list containing all the arguments passed to the program.
 * Return: A total count of the characters printed.
 */
int parser(const char *main_string, conver_t function_list[], va_list arg_list)
{
	int i, j, _return_val, printed_chars;

	printed_chars = 0;
	for (i = 0; main_string[i] != '\0'; i++)
	{
		if (main_string[i] == '%')
		{
			for (j = 0; function_list[j].symbol != NULL; j++)
			{
				if (main_string[i + 1] == function_list[j].symbol[0])
				{
					_return_val = (function_list[j].func(arg_list));
					if (_return_val == (-1))
						return (-1);
					printed_chars += _return_val;
					break;
				}
			}
			if (function_list[j].symbol == NULL && main_string[i + 1] != ' ')
			{
				if (main_string[i + 1] != '\0')
				{
					_writechar(main_string[i]);
					_writechar(main_string[i + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_writechar(main_string[i]);
			printed_chars++;
		}
	}
	return (printed_chars);
}
