#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include "main.h"


/**
 * checker - The function checks for the converstion specifiers presence
 * @format: a constant pointer to character (string) that contain the basic
 * format string provaided to the _printf function
 * @arguments: a pointer to a variable of type va_list that contain all the
 * variable arguments passed to the _printf function for converstion
 * @buffsize: a number of type size_t that contain the total size of the
 * resulted string to allocate space in the heap
 *
 * Description: The function checks for any occur of converstion specifiers in
 * the format string provied to _printf function and if any found it passes the
 * format string to other functions depending on the specifier to be modified
 *
 * Return: a pointer to the final string after finishing all convertion needed
 */

const char *checker(const char *format, va_list *arguments, size_t buffsize)
{
	char *buffer;
	converstion spec[] = {
		{spec_c, 'c'},
		{spec_s, 's'},
		{spec_di, 'd'},
		{spec_di, 'i'},
		{spec_b, 'b'},
		{spec_u, 'u'},
		{spec_o, 'o'},
		{spec_x, 'x'},
		{spec_X, 'X'},
		{NULL, '%'},
		{NULL, '\0'}
	};
	int ccount, scount, buffcount;

	buffcount = 0;
	buffer = malloc(buffsize + 1);
	if (buffer == NULL)
		return (NULL);
	for (ccount = 0; format && format[ccount]; ccount++)
	{
		for (scount = 0; format[ccount] == '%' && spec[scount].specifier; scount++)
		{
			if (format[ccount + 1] == spec[scount].specifier)
			{
				if (scount < 9)
					buffcount = spec[scount].specfunc(buffer, arguments, buffcount);
				else
					buffcount = spec_per(buffer, buffcount);
				ccount += 2;
				scount = -1;
			}
		}
		if (format[ccount])
		{
			buffer[buffcount] = format[ccount];
			buffcount++;
		}
		else
		{
			break;
		}
	}
	if (buffer[buffcount])
		buffer[buffcount] = '\0';
	return (buffer);
}
