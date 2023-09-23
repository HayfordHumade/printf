#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * p_c - function handles the format specifier %c
 * @ap: variadic list which contains arguments
 * @result: buffer to store the output
 * @position: number of characters printed so far
 *
 * Description: this function handles character arguments using the
 * specifier %c in the _printf function.
 * function printing a special character from an argument.
 * Return: nothing.
 */
void p_c(va_list ap, char *result, int *position)
{
	int c;

	/* c holds the character to be printed */
	c = va_arg(ap, int);
	/* print character to the screen */
	result[*position] = c;
	/* increase position */
	(*position)++;
}
/**
 * p_s - function handles the format specifier %s
 * @ap: variadic list which contains arguments
 * @result: buffer to store the output
 * @position: number of characters printed so far
 *
 * Description: this function handles string arguments using the
 * specifier %s in the _printf function.
 * Return: nothing.
 */
void p_s(va_list ap, char *result, int *position)
{
	char *s;
	int i;

	/* s holds the string to be printed */
	s = va_arg(ap, char *);
	/* check s for NULL */
	if (s != NULL)
	{
		i = 0;
		/* store string in result */
		while (s[i] != '\0')
			result[(*position)++] = s[i++];
	}
}
/**
 * p_p - function handles the format specifier %% or \%
 * @ap: variadic list which contains arguments
 * @result: buffer to store the output
 * @position: number of characters printed so far
 *
 * Description: this function handles the printing of %
 * Return: nothing.
 */
void p_p(va_list ap, char *result, int *position)
{
	/* p holds the % character */
	char p = '%';

	(void)ap;
	/* write the % character to screen */
	result[*position] = p;
	/* increase position */
	(*position)++;
}
