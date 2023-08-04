#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * _atoi - converts a string to an integer
 * @argc: string to be converted
 * @argv:command.
 * Return: the int converted from the string
 */

int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc >= 1)


	if (argc != 3)

	{
	printf("Error\n");

	return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	result = num1 * num2;

		printf("%d\n", result);

	return (0);
}
