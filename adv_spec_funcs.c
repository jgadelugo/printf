#include "holberton.h"

/**
 * rot13_find - encodes a string using rot13
 * @s: string to encode
 * Return: encoded to rot13
 */

char *rot13_find(va_list s)
{
	int i, x, temp;
	char check[] = "AaZz";
	char ntom[] = "NOPQRSTUVWXYZABCDEFGHIJKLM";
	char *arg;

	arg = va_arg(s, char *);

	for (i = 0; arg[i] != '\0'; i++)
		for (x = 0; x < 2; x++)
			if (arg[i] >= check[x] && arg[i] <= check[x + 2])
			{
				temp = (arg[i] - 65 - (x * 32));
				arg[i] = (ntom[temp] + (x * 32));
			}
	return (arg);
}
