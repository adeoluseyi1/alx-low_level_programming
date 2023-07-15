#include <stdio.h>
/**
* main - this is the main function
*
* Return:always 0
*/

int main(void)
{

	char a = 'a';

	for (a = 'z'; a >= 'a'; a--)
		putchar(a);

	putchar('\n');

	return (0);
}
