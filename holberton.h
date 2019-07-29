#ifndef PRINTF_H
#define PRINTF_H

#define BUFSIZE 1024
#include <stdarg.h>

/**
 * struct spec_types - Struct to get function of specifier
 * @spec: specifier
 * @f: The function associated
 */
typedef struct spec_types
{
	char *spec;
	int *(*f)();
} s_types;

char *(*get_spec_func(char s))(va_list);
int _printf(const char *format, ...)


#endif /*PRINTF_H*/
