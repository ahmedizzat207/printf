#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"


/**
 * _printf - The function produces output acoording to a format as the printf
 * function
 * @format: a constant pointer to a character (string) which contain the string
 * solid fromat with it's specification of arguments and further instructions
 *
 * Description: The function is variadic to mimic the printf function work as
 * it should take a string as a essential argument that specifiy the number and
 * type of the variable arguments and further infomation on how to print these
 * variables
 *
 * Return: an integer that represent the number of characters printed in the
 * stdout (excluding the null byte used to end the string)
 */

int _printf(const char *format, ...)
{
	va_list arguments, buffstore;
	size_t buffsize;

	va_start(arguments, format);
	va_start(buffstore, format);
	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	buffsize = sizecount(format, &buffstore);
	format = checker(format, arguments, buffsize);
	buffsize = _strlen(format);
	write(1, format, _strlen(format));
	free((void *)format);
	return (buffsize);
}
