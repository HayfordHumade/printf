#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints a string in a specified format
 * @format: string format
 * @...: ellipsis indicating variable number of arguments
 *
 * Description: prints a string in a specified format based on
 * format specifiers such as %s, %%, etc
 * Return: nothing.
 */
int _printf(const char *format, ...)
{
	const char *current;
	va_list ap;
	unsigned int n_chars;

	void (*ptr)(va_list, unsigned int *);

	if (format == NULL)
		return (-1);

	current = format;
	va_start(ap, format);

	while (*current != '\0')
	{
		if (*current == '%')
		{
			/* assign ptr to the call back function */
			ptr = get_p_function(current + 1);
			/* call the function */
			if (ptr != NULL)
				ptr(ap, &n_chars);
			current += 2;
		}
		else if (*current == '\\')
		{
			/* do something. */
			current += 2;
		}
		else
		{
			write(1, current, 1);
			n_chars++;
			current++;
		}
	}
	va_end(ap);

	return (n_chars);
}
