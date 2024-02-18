#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * sizeof_s - The function calculates the size of the string passed to the
 * _printf function as an argument
 * @buffsize: a pointer to a variable of type va_list that contain the strin
 * to calculate it's length
 * @specoccur: an integer number that hold the previous occurance of other
 * converstion specifiers
 *
 * Return: a number of type size_t that contain the lenght of the string
 */

size_t sizeof_s(va_list *buffsize, int specoccur)
{
	int count;
	char *string;

	for (count = 1; count < specoccur; count++)
		va_arg(*buffsize, char *);
	string = va_arg(*buffsize, char *);
	return (_strlen(string));
}
