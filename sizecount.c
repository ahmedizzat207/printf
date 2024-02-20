#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * sizecount - The function counts the total size needed for the buffer to
 * store the resulted string from _printf function
 * @format: a pointer to character (string) the contain the string passed to
 * the _printf function which contain the number and types of the passed
 * variable arguments
 * @buffsize: a pointer to a variable of type va_list which contain the
 * variable arguments list passed to _printf fucntion
 *
 * Return: a number of type size_t contain the size needed to store the final
 * result of _printf function
 */

size_t sizecount(const char *format, va_list *buffsize)
{
	int ccount, scount;
	size_t buffcount;
	counter spsize[] = {
		{sizeof_c, 'c'},
		{sizeof_s, 's'},
		{sizeof_di, 'd'},
		{sizeof_di, 'i'},
		{NULL, '%'},
		{NULL, '\0'}
	};

	buffcount = 0;
	for (ccount = 0; format && format[ccount]; ccount++)
	{
		for (scount = 0; format[ccount] == '%' && spsize[scount].specifier; scount++)
		{
			if (format[ccount + 1] == spsize[scount].specifier)
			{
				if (scount < 4)
					buffcount += spsize[scount].specfunc(buffsize);
				else
					buffcount--;
				break;
			}

		}
		buffcount++;
	}
	return (buffcount);
}
