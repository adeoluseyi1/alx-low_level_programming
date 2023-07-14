#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
* main - this is thelast digit main function
*
* Return:always 0
*/
int main(void)
{
	int n;

	int r;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	r = n % 10
	if (r > 5)
		printf("last digit of %d is %d is greater than 5\n" n, r);
	if (r == 0)
		printf("last digit of %d is %d is 0\n" n, r);
	if (r < 6 && !=0)
		printf("last digit is of %d is %d is less than 6 and not 0\n" n, r);
	return (0);
}
