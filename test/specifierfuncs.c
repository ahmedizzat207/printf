#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * spec_c - The function replace the converstion specifiers "%c" with the
 * argument value
 * @buffer: a pointer to a character (string) that contain the string format
 * passed to _printf function until the converstion specifier
 * @arguments: a variable of the type va_list that contains the variable
 * arguments passed to _printf as to replace converstion specifiers
 * @buffcount: an integer contains the buffer characters count
 *
 * Return: an integer contains the last buffer character count after replacing
 * the converstion specifier with it's corresponding value
 */

int spec_c(char *buffer, va_list arguments, int buffcount)
{
	buffer[buffcount] = (char)va_arg(arguments, int);
	buffcount++;
	return (buffcount);
}


/**
 * spec_s - The function replace the converstion specifiers "%s" with the
 * correspondent argument value
 * @buffer: a pointer to a character (string) that contain the string format
 * passed to _printf function until the converstion specifier
 * @arguments: a variable of the type va_list that contains the variable
 * arguments passed to _printf as to replace converstion specifiers
 * @buffcount: an integer contains the buffer characters count
 *
 * Return: an integer contains the last buffer character count after replacing
 * the converstion specifier with it's corresponding value
 */

int spec_s(char *buffer, va_list arguments, int buffcount)
{
	char *string;
	int strcount;

	string = va_arg(arguments, char *);
	for (strcount = 0; string[strcount]; strcount++, buffcount++)
		buffer[buffcount] = string[strcount];
	return (buffcount);
}


/**
 * spec_per - The function replace the double percentage signs "%%" with one
 * @buffer: a pointer to a charcter (string) that contain the string format
 * passed to _printf function until the converstion specifier
 * @arguments: a variable of the type va_list that contains the variable
 * arguments passed to _printf
 * @buffcount: an integer contains the buffer characters count
 *
 * Return: an integer contains the last buffer character count after replacing
 * the percentage sign
 */

int spec_per(char *buffer, int buffcount)
{
	buffer[buffcount] = '%';
	buffcount++;
	return (buffcount);
}


/**
 * _strlen - The function count the passed string length
 * @format: a pointer to character (string) to calculate it's length
 *
 * Return: an integer of type (size_t) containing the string length
 */

size_t _strlen(const char *format)
{
	size_t count;

	for (count = 0; format[count]; count++)
		;
	return (count);
}
