#include <stdio.h>

int main(void)
{
	int a[5] = { 1,2,3 };

	char b[5] = { 'A', 'B', 'C' };

	int i;

	for (i = 0; i < 5; i++)
	{
		printf(" %d ", a[i]);
	}

	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf(" %c ", b[i]);
	}




	return 0;
}