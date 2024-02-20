#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * sizeof_s - The function calculates the size of the string passed to the
 * _printf function as an argument
 * @buffsize: a pointer to a variable of type va_list that contain the string
 * to calculate it's length
 *
 * Return: a number of type size_t that contain the length of the string
 */

size_t sizeof_s(va_list *buffsize)
{
	char *string;

	string = va_arg(*buffsize, char *);
	if (string == NULL)
		return (_strlen("(null)"));
	return (_strlen(string) - 2);
}


/**
 * sizeof_c - The function execute the va_arg macro to flush the character
 * contained in the variable argument
 * @buffsize: a pointer to a variable of type va_list that contain the
 * character to manage the arguments flow
 *
 * Return: a number of type size_t that contain the length of the character
 * which is -1 because we septeract the 2 converstion characters
 */

size_t sizeof_c(va_list *buffsize)
{
	char size;

	size = (char)va_arg(*buffsize, int);
	return (sizeof(size) - 2);
}


/**
 * sizeof_d - The function calculates the number of digits in the integer to
 * therefore convert it to a string
 * @buffsize: a pointer to a variable of type va_list that contain the integer
 * to calculate it's digits
 *
 * Return: a number of type size_t that contain the number of digit of the
 * specific integer
 */

size_t sizeof_di(va_list *buffsize)
{
	int integer;
	int exponent;

	integer = va_arg(*buffsize, int);
	for (exponent = 9; exponent  && !(integer / _pow(10, exponent)); exponent--)
		;
	return (exponent - 1);
}
