#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);
void (*(get_p_function(const char *s)))(va_list, char *, int *);
void p_c(va_list ap, char *result, int *position);
void p_s(va_list ap, char *result, int *position);
void p_p(va_list ap, char *result, int *position);
/**
 * struct sp - a structure
 *
 * @s: is a string
 * @f: callback function
 */
typedef struct sp
{
	char *s;
	void (*f)(va_list, char *, int *);
} sp_t;

#endif	/* main.h */
