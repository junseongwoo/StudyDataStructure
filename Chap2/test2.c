#include <stdio.h>

int main(void)
{
	int array[4];
	int* p = array;

	*p = 10;
	*(p + 1) = 20;
	p[2] = p[0] + p[1];
	p[3] = 40;

	printf("%d\n", &p[0]);
	printf("%d\n", &p[2]);
	printf("%d\n", &p[1]);

	return 0;
}