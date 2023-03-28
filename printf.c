#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	va_start(args, format);

	while (*format != '\0') {
		if (*format == '%') {
			format++; // skip over the %
			switch (*format) {
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					fprintf(stderr, "Error: invalid conversion specifier '%%%c'\n", *format);
					return -1;
			}
		} else {
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return count;
}
