#include <stdio.h>
#include <stdarg.h>
#include "main.h"


/**
 * spec_u - The function write the corrsponding value of the unsigned integer
 * converstion specifier passed as a variable argument to _printf function
 * @buffer: a pointer to a character (string) that contain the final version of
 * the string that the _printf function should print until the last conversion
 * specifier
 * @arguments: a pointer to the variable arguments list passed to the _printf
 * function
 * @buffcount: an integer number containing the number of the last buffer
 * element that the function should start writing from
 *
 * Return: an integer the contain the last buffer element modified by the
 * function
 */

int spec_u(char *buffer, va_list *arguments, int buffcount)
{
	long int integer;
	int exp;

	integer = va_arg(*arguments, unsigned int);
	for (exp = 9; exp >= 0; exp--)
	{
		if (integer / _pow(10, exp))
		{
			for (; exp >= 0; exp--, buffcount++)
				buffer[buffcount] = ((integer / _pow(10, exp)) % 10) + 48;
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
 * spec_o - The function write the corrosponding value of the unsigned integer
 * converted to octal base from _printf function variable arguments
 * @buffer: a pointer to a character (string) that contain the final version of
 * the string that the _printf function should print until the last conversion
 * specifier
 * @arguments: a pointer to the variable arguments list passed to the _printf
 * function
 * @buffcount: an integer number containing the number of the last buffer
 * element that the function should start writing from
 *
 * Return: an integer the contain the last buffer element modified by the
 * function
 */

int spec_o(char *buffer, va_list *arguments, int buffcount)
{
	long int integer;
	int exp;

	integer = va_arg(*arguments, unsigned int);
	if (integer == 0)
	{
		buffer[buffcount] = '0';
		buffcount++;
	}
	for (exp = 11; exp >= 0; exp--)
	{
		if (integer / _pow(8, exp))
		{
			for(; exp >= 0; exp--, buffcount++)
			{
				buffer[buffcount] = (integer / _pow(8, exp)) + 48;
				integer %= _pow(8, exp);
			}
		}
	}
	return (buffcount);
}


/**
 * spec_x - The function write the corrosponding value of the unsigned integer
 * converted to hexadecimel base with small letters from _printf function
 * variable arguments
 * @buffer: a pointer to a character (string) that contain the final version of
 * the string that the _printf function should print until the last conversion
 * specifier
 * @arguments: a pointer to the variable arguments list passed to the _printf
 * function
 * @buffcount: an integer number containing the number of the last buffer
 * element that the function should start writing from
 *
 * Return: an integer that contain the last buffer element modified by the
 * function
 */

int spec_x(char *buffer, va_list *arguments, int buffcount)
{
	long int integer;
	int exp;

	integer = va_arg(*arguments, unsigned int);
	if (integer == 0)
	{
		buffer[buffcount] = '0';
		buffcount++;
	}
	for (exp = 7; exp >= 0; exp--)
	{
		if (integer / _pow(16, exp))
		{
			for(; exp >= 0; exp--, buffcount++)
			{
				if ((integer / _pow(16, exp)) < 10)
					buffer[buffcount] = (integer / _pow(16, exp)) + 48;
				else
					buffer[buffcount] = (integer / _pow(16, exp)) + 87;
				integer %= _pow(16, exp);
			}
		}
	}
	return (buffcount);
}


/**
 * spec_X - The function write the corrosponding value of the unsigned integer
 * converted to hexadecimal base with capital letters from _printf function
 * variable arguments
 * @buffer: a pointer to a character (string) that contain the first version of
 * the string that the _printf function should printf until the last conversion
 * specifier
 * @arguments: a pointer to the variable arguments list passed to the _printf
 * function
 * @buffcount: an integer number containing the number of the last buffer
 * element that the function should start writing from
 *
 * Return: an integer that contain the last buffer element modified by the
 * function
 */

int spec_X(char *buffer, va_list *arguments, int buffcount)
{
	long int integer;
	int exp;

	integer = va_arg(*arguments, unsigned int);
	if (integer == 0)
	{
		buffer[buffcount] = '0';
		buffcount++;
	}
	for (exp = 7; exp >= 0; exp--)
	{
		if (integer / _pow(16, exp))
		{
			for (; exp >= 0; exp--, buffcount++)
			{
				if ((integer / _pow(16, exp)) < 10)
					buffer[buffcount] = (integer / _pow(16, exp)) + 48;
				else
					buffer[buffcount] = (integer / _pow(16, exp)) + 55;
				integer %= _pow(16, exp);
			}
		}
	}
	return (buffcount);
}


/**
 * spec_S - The function write the string passed to the _printf function
 * in the buffer
 * @buffer: a pointer to a character (string) that contain the string which
 * the _printf function should print
 * @arguments: a pointer to a variable arguments list that contain the string
 * to write in the buffer
 * @buffcount: an integer that contain the number of the last buffer character
 * where the function should start modifing
 *
 * Return: an integer that contain the number of the last modified by the
 * function
 */

int spec_S(char *buffer, va_list *arguments, int buffcount)
{
	char *string;
	int count;
	int charcount;
	int integer;
	int exp;

	string = va_arg(*arguments, char *);
	if (!string)
		return (_strlen("(null)"));
	for (count = 0, charcount = 0; string[count]; count++, buffcount++, charcount++)
	{
		if (string[count] >= 32 && string[count] < 127)
		{
			buffer[buffcount] = string[count];
		}
		else
		{
			integer = string[count];
			buffer[buffcount] = '\\';
			buffcount++;
			buffer[buffcount] = 'x';
			buffcount++;
			for (exp = 1; exp >= 0; exp--, buffcount++, charcount++)
			{
				if ((integer / _pow(16, exp)) < 10)
					buffer[buffcount] = (integer / _pow(16, exp)) + 48;
				else
					buffer[buffcount] = (integer / _pow(16, exp)) + 55;
				integer %= _pow(16, exp);
				buffcount--;
			}
		}
	}
	return (buffcount);
}
