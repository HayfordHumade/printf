#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * get_p_function - calls back a function
 *
 * @s: has the character to compare with
 *
 * Description: calls back a function when it finds a match
 * Return: nothing.
 */
void (*get_p_function(const char *s))(va_list, unsigned int *)
{
	sp_t sf[] = {
		{"c", p_c},
		{"s", p_s},
		{"%", p_p},
		{"d", p_d},
		{"i", p_i},
		{NULL, NULL}
	};
	int i;

	/* check s for NULL */
	if (s != NULL)
	{
		i = 0;
		/* find index of matching character */
		while (sf[i].s != NULL && *sf[i].s != *s)
			i++;
		/* return corresponding function */
		return (sf[i].f);
	}
	else
		return (NULL);
}
