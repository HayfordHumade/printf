<h1>About the custom Printf Project</h1>

This project is a collaboration between @mwunnam and @HayfordHumade.

We are building a custom C printf function as part of our ALX Sofware Engineering training program.
The printf function is a variadic function whose prototype is of the form:

	int printf(const char *format, ...);

This README file lists all the files in this directory and also describes its prototypes.

<h2>📚Files</h2>

1. Filename:	&emsp; 0-printf.c
   - Prototype:	&emsp; `int _printf(const char *format, ...);`
   - Description:&emsp; prints a string in a specified format and returns the number of characters printed.
 
2. Filename:	&emsp; 1-specifier_functions.c
   - Prototype:	&emsp; check main.h for prototypes
   - Description:&emsp; contains a series of functions that handle specifiers

3. Filename:	&emsp; 2-get_specifier_function.c
   - Prototype: &emsp; `void (*(get_p_function(const char *s)))(va_list ap, unsigned int *n_chars);`
   - Description: &emsp; calls a specifier function

4. Filename: &emsp; main.h
   - Description: &emsp; a header file
5. This was done with planning

6. This will make it work as  we want it to 
