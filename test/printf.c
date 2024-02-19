#include <stdio.h>
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
	printf("printf:step1\n");
	buffsize = sizecount(format, &buffstore);
	printf("printf:step2: return from sizecount and buffsize value equle: %ld\n", buffsize);
	format = checker(format, arguments, buffsize);
	printf("printf:step3: return from checker and format is %s\n", format);
	write(1, format, _strlen(format));
	printf("printf:step4: format should be printed twice\n");
	if (format[0] == '%' && buffsize == 1)
		return (-1);
	printf("printf:step5: final format size should equel step2 buffsize = %ld\n", buffsize);
	free((void *)format);
	return (buffsize);
}
