#include <stdio.h>
#include "main.h"


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
	if (count == 0)
		return (1);
	return (count);
}



/**
 * _pow - The function calculate the exponential of the first integer to the
 * power of the second integer
 * @basic: an integer that hold the basic of the exponent
 * @power: an integer that hold the power of hte exponent
 *
 * Return: the result of the exponent
 */

long int _pow(int basic, int power)
{
	long int result;

	result = 1;
	for (; power > 0; power--)
		result *= basic;
	return (result);
}
