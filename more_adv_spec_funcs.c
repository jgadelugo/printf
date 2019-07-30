#include "holberton.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * hex_find - convert int to hex
 * @n: integer
 * Return: hex
 */

char *hex_find(va_list n)
{
	char *hexaDeciNum;
	int i, temp, arg, hold, size;

	arg = va_arg(n, int);

	for (hold = arg, size = 0; hold; hold /= 16)
		size++;
	hexaDeciNum = malloc((size + 1) * sizeof(char));
	if (hexaDeciNum == NULL)
		return (NULL);
	for (i = 0; arg; arg /= 16, i++)
	{
		temp = arg % 16;
		if (temp < 10)
			hexaDeciNum[i] = (temp + '0');
		else
			hexaDeciNum[i] = (temp + 'a' - 10);
	}
	return (rev_string(hexaDeciNum, _strlen(hexaDeciNum)));
}
/**
 * HEX_find - convert int to hex
 * @n: integer
 * Return: hex
 */

char *HEX_find(va_list n)
{
	char *hexaDeciNum;
	int i, temp, arg, hold, size;

	arg = va_arg(n, int);

	for (hold = arg, size = 0; hold; hold /= 16)
		size++;
	hexaDeciNum = malloc((size + 1) * sizeof(char));
	if (hexaDeciNum == NULL)
		return (NULL);
	for (i = 0; arg; arg /= 16, i++)
	{
		temp = arg % 16;
		if (temp < 10)
			hexaDeciNum[i] = (temp + '0');
		else
			hexaDeciNum[i] = (temp + 'A' - 10);
	}
	return (rev_string(hexaDeciNum, _strlen(hexaDeciNum)));
}
/**
 * address_find - get address
 * @n: integer
 * Return: address
 */

char *address_find(va_list n)
{
	char *address;
	int i, temp, arg, hold, size;

	arg = va_arg(n, int);

	for (hold = arg, size = 0; hold; hold /= 16)
		size++;
	address = malloc((size + 3) * sizeof(char));
	if (address == NULL)
		return (NULL);
	address[0] = '0';
	address[1] = 'x';
	for (i = 2; arg; arg /= 16, i++)
	{
		temp = arg % 16;
		if (temp < 10)
			address[i] = (temp + '0');
		else
			address[i] = (temp + 'A' - 10);
	}
	return (rev_string(address, _strlen(address)));
}
