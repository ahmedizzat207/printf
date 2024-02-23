#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * sizeof_o - The function calculate the size of the unsigned integer number
 * converted to octal base passed to _printf in the arguments list
 * @arguments: a pointer to a variable arguments list va_list that contain
 * the variable to calculate it's length
 *
 * Return: a number of type size_t that contain the number's digits to be
 * printed by _printf function
 */

size_t sizeof_o(va_list *arguments)
{
	long int integer;
	int exp;

	integer = va_arg(*arguments, unsigned int);
	for (exp = 11; exp >= 0 && !(integer / _pow(8, exp)); exp--)
		;
	if (integer == 0)
		return (-1);
	else
		return (exp - 1);
}



/**
 * sizeof_x - The function calculates the size of the unsigned integer number
 * converted to octal base passed to _printf in the arguments list
 * @arguments: a pointer to a variable arugments list va_list that contain
 * the variable to calculate it's length
 *
 * Return: a number of type size_t that contain the number's digits to be
 * printed by _printf function
 */

size_t sizeof_x(va_list *arguments)
{
	long int integer;
	int exp;

	integer = va_arg(*arguments, unsigned int);
	for (exp = 7; exp >= 0 && !(integer / _pow(16, exp)); exp--)
		;
	if (integer == 0)
		return (-1);
	else
		return (exp - 1);
}


/**
 * sizeof_S - The function calculates the size of the string passed to the
 * _printf function
 * @arguments: a pointer to a variable arguments list va_list that contain
 * the string to calculate it's length
 *
 * Description: The function calculates the size of the string passed to the
 * _printf function with specific difference of changing specific characters
 *
 * Return: a number of type size_t that contain the number's digits to be
 * printed by _printf function
 */

size_t sizeof_S(va_list *arguments)
{
	char *string;
	int count, buffcount;


	string = va_arg(*arguments, char *);
	if (!string)
		return (_strlen("(null)"));
	for (count = 0, buffcount = 0; string && string[count] ; count++, buffcount++)
	{
		if ((string[count] > 0 && string[count] < 32) || string[count] >= 127)
			buffcount += 4;
	}
	return (buffcount - 2);
}
