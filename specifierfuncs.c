#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * spec_c - The function replace the converstion specifiers "%c" with the
 * argument value
 * @buffer: a pointer to a character (string) that contain the string format
 * passed to _printf function until the converstion specifier
 * @arguments: a pointer to a variable of the type va_list that contains the
 * variable arguments passed to _printf as to replace converstion specifiers
 * @buffcount: an integer contains the buffer characters count
 *
 * Return: an integer contains the last buffer character count after replacing
 * the converstion specifier with it's corresponding value
 */

int spec_c(char *buffer, va_list *arguments, int buffcount)
{
	buffer[buffcount] = (char)va_arg(*arguments, int);
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

int spec_s(char *buffer, va_list *arguments, int buffcount)
{
	char *string;
	int strcount;

	string = va_arg(*arguments, char *);
	if (string == NULL)
		string = "(null)";
	for (strcount = 0; string[strcount]; strcount++, buffcount++)
		buffer[buffcount] = string[strcount];
	return (buffcount);
}


/**
 * spec_di - The function calculate the number of digits in an integer and
 * write the number in the buffer
 * @buffer: a pointer to a character (string) that contain the string format
 * passed to _printf function until the converstion specifier
 * @arguments: a pointer to a variable of the type va_list that contains the
 * variable arguments passed to _printf as to replace converstion specifiers
 * @buffcount: an integer contains the buffer characters count
 *
 * Return: an integer contains the last buffer character count after replacing
 * the integer converstion specifier
 */

int spec_di(char *buffer, va_list *arguments, int buffcount)
{
	long int integer;
	int exponent;

	integer = (long int)va_arg(*arguments, int);
	for (exponent = 9; exponent >= 0; exponent--)
	{
		if (integer < 0)
		{
			integer = -integer;
			buffer[buffcount] = '-';
			buffcount++;
		}
		if (integer / _pow(10, exponent))
		{
			for (; exponent >= 0; exponent--, buffcount++)
				buffer[buffcount] = (((integer / _pow(10, exponent)) % 10) + 48);
		}
	}
	if (integer == 0)
	{
		buffer[buffcount] = '0';
		buffcount++;
	}
	return (buffcount);
}


/**
 * spec_b - The function calculate and write the binary number converted from
 * an unsigned integer in the buffer
 * @buffer: a pointer to a character (string) that contain the string that
 * should be printed by _printf until the converstion specifier
 * @arguments: a pointer to a variable of type va_list that contain the
 * variable arguments passed to _printf replace converstion specifier
 * @buffcount: an integer that contain the buffer characters count
 *
 * Return: an integer to the last number of characters modified by the function
 */

int spec_b(char *buffer, va_list *arguments, int buffcount)
{
	unsigned long int integer;
	int exp;

	integer = va_arg(*arguments, unsigned int);
	if (integer == 0)
	{
		buffer[buffcount] = '0';
		buffcount++;
	}
	for (exp = 31; exp >= 0; exp--)
	{
		if (integer / _pow(2, exp))
		{
			for (; exp >= 0; exp--, buffcount++)
			{
				buffer[buffcount] = ((integer / _pow(2, exp)) + 48);
				integer %= _pow(2, exp);
			}
		}
	}
	return (buffcount);
}

/**
 * spec_per - The function replace the double percentage signs "%%" with one
 * @buffer: a pointer to a charcter (string) that contain the string format
 * passed to _printf function until the converstion specifier
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
