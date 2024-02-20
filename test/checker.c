#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>


/**
 * checker - The function checks for the converstion specifiers presence
 * @format: a constant pointer to character (string) that contain the basic
 * format string provaided to the _printf function
 * @arguments: a variable of type va_list that contain all the variable
 * arguments passed to the _printf function for converstion
 *
 * Description: The function checks for any occur of converstion specifiers in
 * the format string provied to _printf function and if any found it passes the
 * format string to other functions depending on the specifier to be modified
 *
 * Return: a pointer to the final string after finishing all convertion needed
 */

const char *checker(const char *format, va_list arguments, size_t buffsize)
{
	char *buffer;
	converstion specifiers[] = {
		{spec_c, 'c'},
		{spec_s, 's'},
		{NULL, '%'},
		{NULL, '\0'}
	};
	int charcount, speccount, buffcount;

	printf("checker:step1\n");
	buffcount = 0;
	buffer = malloc(buffsize);
	if (buffer == NULL)
		return (NULL);
	for (charcount = 0; format && format[charcount]; charcount++)
	{
		printf("checker:step2: inside first loop charcount = %d format[charcount] = %c\n", charcount, format[charcount]);
		for (speccount = 0; format[charcount] == '%' && specifiers[speccount].specifier; speccount++)
		{
			printf("checker:step3: inside second loop format[charcount] = %c and specifier[speccount].specifier = %c\n", format[charcount], specifiers[speccount].specifier);
			if (specifiers[speccount].specifier == format[charcount + 1])
			{
				printf("checker:step4: inside condition buffer = %s\n", buffer);
				if (speccount != 2)
					buffcount = specifiers[speccount].specfunc(buffer, arguments, buffcount);
				else
					buffcount = spec_per(buffer, buffcount);
				charcount += 2;
				speccount = -1;
			}
		}
		buffer[buffcount] = format[charcount];
		buffcount++;
	}
	printf("checker:step5: final step in checker buffer = %s\n", buffer);
	return (buffer);
}
