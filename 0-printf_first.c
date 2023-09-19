#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Function produces an output according to a format
 * @format: String composes of zero or more derivatives
 *
 * Description: Building a replica printf function
 * Return: Number of characters printed (excluding ull byte)
 */
int _printf(const char *format, ...)
{
	va_list ap;	/* Holds all arguments passed into _printf */
	int n_char, i, j;
	char *str, *tmp;

	va_start(ap, format);
	n_char = 0;
	j = 0;
	if (format == NULL)
		return (-1);
	while (format[n_char] != '\0')
		n_char++;	/* Number of characters in format = its size */
	str = malloc(n_char + 1);	/* Allocate memory for str */
	for (i = 0; i < n_char; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			str[j++] = (char)va_arg(ap, int);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			tmp = va_arg(ap, char *);
			while (*tmp != '\0')
				str[j++] = *tmp++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			str[j++] = '%';
			i++;
		}
		else
			str[j++] = format[i];
	}
	str[j] = '\0';
	va_end(ap);
	write(1, str, j);
	free(str);

	return (j);
}
