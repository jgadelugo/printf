#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * octal_find - converts decimal to octal numbers
 * @n: octal number to print
 * Return: pointer to string
 */

char *octal_find(va_list n)
{
        unsigned long int pos, temp, result, oct, i;
        char *string;

        oct = va_arg(n, unsigned long int);
        result = i = 0;
        pos = 1;

        while (oct)
        {
                result += (oct % 8) * pos;
                oct /= 8;
                pos *= 10;
                i++;
        }

        temp = i;
        pos /= 10;
        string = malloc(temp * sizeof(char) + 1);

        for (i = 0 ; i < temp; i++)
        {
                string[i] = ((result / pos) % 10) + '0';
                pos /= 10;
        }
        string[i] = '\0';

	return (string);
}
