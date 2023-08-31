#include "main.h"

/**
 * binary_to_uint_custom - converts a binary number to unsigned int
 * @binary_str: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint_custom(const char *binary_str)
{
	int index;
	unsigned int result = 0;

	if (!binary_str)
	return (0);

	for (index = 0; binary_str[index]; index++)
	{
	if (binary_str[index] < '0' || binary_str[index] > '1')
	return (0);
	result = 2 * result + (binary_str[index] - '0');
	}

	return (result);
}
