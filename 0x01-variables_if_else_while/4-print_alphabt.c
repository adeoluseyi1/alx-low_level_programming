#include <stdio.h>
/**
* main - this is the main function
*
* Return:always 0
*/

int main(void)
{
	char b = 'a';
	while (b <= 'z')

	{
		if (b != 'q' && b != 'e')
		putchar(b);
		b++;
	}

	putchar('\n');
	return (0);
}
