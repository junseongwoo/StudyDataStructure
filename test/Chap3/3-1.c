#include <stdio.h>

void main()
{
	int i, sale[4] = { 157, 209, 251, 312 };

	for (i = 0; i < 4; i++)
	{
		printf("\naddress : %u sale[%d] = %d", &sale[i], i, sale[i]);
	}

	getchar();
}