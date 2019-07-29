#include "holberton.h"
#include <stddef.h>


/**
 * _printf - function that prints output
 * @format: is a charachter string with 0 to 3 directives
 * Return: the number of charachters to be printed
 */

int _printf(const char *format, ...)
{
	va_list valist;
	int i, buffend, hlen = 0;
	double totalBuffer = 0;
	double *total = &totalBuffer;
	char *holder;
	char buffer[BUFSIZE];
	char *(*spec_func)(va_list) = NULL;

	if (!format)
		return (-1);
	va_start(valist, format);

	/*initialize buffer */
	for (i = 0; i < BUFSIZE; i++)
		buffer[i] = 0;
	/*check format and select arg*/
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			spec_func = get_spec_func(format[i]);
			if (spec_func)
				holder = spec_func(valist);
			else
				holder = nothing_found(format[i]);
			hlen = _strlen(holder);
			buffend = alloc_buffer(holder, hlen, buffer, buffend, total);
		}
		else
		{
			holder = chartos(format[i]);
			buffend = alloc_buffer(holder, 1, buffer, buffend, total);
		}
	}
	_puts(buffer, buffend);
	va_end(valist);
	return (totalBuffer + buffend);
}
