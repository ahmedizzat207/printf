#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * sizecount - The function counts the total size needed for the buffer to
 * store the resulted string from _printf function
 * @format: a pointer to character (string) the contain the string passed to
 * the _printf function which contain the number and types of the passed
 * variable arguments
 * @buffsize: a pointer to a variable of type va_list which contain the
 * variable arguments list passed to _printf fucntion
 *
 * Return: a number of type size_t contain the size needed to store the final
 * result of _printf function
 */

size_t sizecount(const char* format, va_list *buffsize)
{
	int charcount, speccount, specoccur;
	size_t buffcount;
	char specsize[] = {'c', 's', '%', '\0'};

	buffcount = 0;
	specoccur = 0;
	printf("sizecount:step1\n");
	for (charcount = 0; format && format[charcount]; charcount++)
	{
		printf("sizecount:step2: buffcount = %ld and format[charcount] = %c\n", buffcount, format[charcount]);
		for (speccount = 0; format[charcount] == '%' && specsize[speccount]; speccount++)
		{
			printf("sizecount:step3: sepccount = %d\n", speccount);
			if (format[charcount + 1] == specsize[speccount])
			{
				specoccur++;
				if (speccount == 1)
					buffcount += sizeof_s(buffsize, specoccur) - 2;
				else
					buffcount--;
				break;
			}

		}
		buffcount++;
	}
	printf("sizecount:step5: buffcount = %ld\n", buffcount);
	return (buffcount);
}	
