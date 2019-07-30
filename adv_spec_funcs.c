#include "holberton.h"
#include <stdlib.h>

/**
 * rot13_find - encodes a string using rot13
 * @s: string to encode
 * Return: encoded to rot13
 */

char *rot13_find(va_list s)
{
	int i, x, temp, len;
	char check[] = "AaZz";
	char ntom[] = "NOPQRSTUVWXYZABCDEFGHIJKLM";
	char *arg, *rot;

	arg = va_arg(s, char *);
	len = _strlen(arg);
	rot = malloc((len + 1) * sizeof(char));
	for (i = 0; arg[i]; i++)
		for (x = 0; x < 2; x++)
			if (arg[i] >= check[x] && arg[i] <= check[x + 2])
			{
				temp = (arg[i] - 65 - (x * 32));
				rot[i] = (ntom[temp] + (x * 32));
			}
	rot[i] = '\0';
	return (rot);
}
/**
 * rev_find - reverse a string
 * @s: input string
 * Return: reversed string
 */
char *rev_find(va_list s)
{
	char *arg, *rev;
	int i, len;

	arg = va_arg(s, char *);
	len = _strlen(arg);
	rev = malloc((len + 1) * sizeof(char));

	len--;
	for (i =0; len >= 0; i++, len--)
		rev[i] = arg[len];
	return (rev);
}
