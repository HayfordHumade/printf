#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * p_c - function handles the format specifier %c
 * @ap: variadic list which contains arguments
 * @n_chars: number of characters printed so far
 *
 * Description: this function handles character arguments using the
 * specifier %c in the _printf function.
 * function printing a special character from an argument.
 * Return: nothing.
 */
void p_c(va_list ap, unsigned int *n_chars)
{
	int c;

	/* c holds the character to be printed */
	c = va_arg(ap, int);
	/* print character to the screen */
	write(1, &c, 1);
	/* increase the number of printed characters by 1 */
	(*n_chars)++;
}
/**
 * p_s - function handles the format specifier %s
 * @ap: variadic list which contains arguments
 * @n_chars: number of characters printed so far
 *
 * Description: this function handles string arguments using the
 * specifier %s in the _printf function.
 * Return: nothing.
 */
void p_s(va_list ap, unsigned int *n_chars)
{
	char *s;
	int size;

	/* s holds the string to be printed */
	size = 0;
	s = va_arg(ap, char *);
	/* compute size of string */
	while (s[size] != '\0')
		size++;
	/* print string on screen */
	write(1, s, size);
	/* increase the number of printed characters */
	(*n_chars) += size;
}
/**
 * p_p - function handles the format specifier %% or \%
 * @ap: variadic list which contains arguments
 * @n_chars: number of characters printed so far
 *
 * Description: this function handles the printing of %
 * Return: nothing.
 */
void p_p(va_list ap, unsigned int *n_chars)
{
	(void)ap;
	char p;

	/* p holds the % character */
	p = '%';
	/* write the % character to screen */
	write(1, &p, 1);
	/* increase the number of printed characters */
	(*n_chars)++;
}
