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
