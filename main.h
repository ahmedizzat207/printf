#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>


int _printf(const char *format, ...);
const char *checker(const char *format, va_list *arguments, size_t buffsize);
size_t sizecount(const char *format, va_list *buffsize);
int spec_c(char *buffer, va_list *arguments, int buffcount);
int spec_s(char *buffer, va_list *arguments, int buffcount);
int spec_di(char *buffer, va_list *arguments, int buffcount);
int spec_b(char *buffer, va_list *arguments, int buffcount);
int spec_u(char *buffer, va_list *arguments, int buffcount);
int spec_o(char *buffer, va_list *arguments, int buffcount);
int spec_x(char *buffer, va_list *arguments, int buffcount);
int spec_X(char *buffer, va_list *arguments, int buffcount);
int spec_per(char *buffer, int buffcount);
size_t sizeof_s(va_list *buffsize);
size_t sizeof_c(va_list *buffsize);
size_t sizeof_di(va_list *buffsize);
size_t sizeof_b(va_list *buffsize);
size_t sizeof_u(va_list *buffsize);
size_t sizeof_o(va_list *buffsize);
size_t sizeof_x(va_list *buffsize);
size_t sizeof_X(va_list *buffsize);
size_t _strlen(const char *format);
long int _pow(int basic, int power);


/**
 * struct converstion - The structure store the value of converstion specifiers
 * and functions related to them
 * @specifier: a character that store the value of a specific converstion
 * specifier
 * @specfunc: a pointer to a function that takes the string format and the
 * arguments variable of type va_list and the character number where the
 * specifier is recognized in the format
 *
 * Description: The structure stores the values of converstion specifiers and
 * the functions that modifies the provided string format by adding the
 * converted variable
 */

typedef struct converstion
{
	int (*specfunc)(char *, va_list *, int);
	char specifier;
} converstion;


/**
 * struct counter - The structure store the value of converstion specifiers and
 * function counts there character number
 * @count: a pointer to a function that takes the variable arguments list of
 * type va_list and calculate it's length
 * @specifier: a character that stor the value of a specific converstion
 * specifier
 *
 * Description: The structure stores the values of converstion specifiers and
 * the function that calculates the length of the variable refered by that
 * specifier
 */

typedef struct counter
{
	size_t (*specfunc)(va_list *);
	char specifier;
} counter;


#endif /* #ifndef MAIN_H */
