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
	if (format == NULL)
		return (-1);
	const char *current;
	char *result;
	va_list ap;
	int size, position;
	void (*ptr)(va_list, char *, int *);

	current = format;
	va_start(ap, format);
	while (format[size] != '\0')
		size++;
	result = malloc(size + 1);
	position = 0;
	while (*current != '\0' && result != NULL)
	{
		if (*current == '%')
		{
			/* assign ptr to the call back function */
			ptr = get_p_function(current + 1);
			/* call the function */
			if (ptr != NULL)
				ptr(ap, result, &position);
			current += 2;
		}
		else
			result[position++] = *(current++);
	}
	va_end(ap);

	result[position] = '\0';
	write(1, result, position);
	/* printf("%d\n", position); */
	return (position);
}
