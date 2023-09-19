#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
void (*(get_p_function(const char *s)))(va_list ap, unsigned int *n_chars);
void p_c(va_list ap, unsigned int *n_chars);
void p_s(va_list ap, unsigned int *n_chars);
void p_p(va_list ap, unsigned int *n_chars);
/**
 * struct sp - a structure
 *
 * @s: is a string
 * @f: callback function
 */
typedef struct sp
{
	char *s;
	void (*f)(va_list ap, unsigned int *n_chars);
} sp_t;

#endif	/* main.h */
