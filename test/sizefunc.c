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

size_t sizeof_s(va_list *buffsize)
{
	char *string;

	printf("sizeof_s:step1\n");
	string = va_arg(*buffsize, char *);
	printf("sizeof_s:step2: string = %s\n", string);
	if (string == NULL)
	{
		printf("sizeof_s:step3: string length = %ld\n", _strlen("(null)"));
		return (_strlen("(null)"));
	}
	printf("sizeof_s:step3: string length = %ld\n", _strlen(string));
	return (_strlen(string) - 2);
}

size_t sizeof_c(va_list *buffsize)
{
	char size;

	size = (char)va_arg(*buffsize, int);
	return (sizeof(size) - 2);
}
