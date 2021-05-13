#include <stdio.h>

void main()
{
	int i, n = 0, * ptr;
	int sale[2][4] = { {63, 84, 140, 130},
					   {157, 209, 251, 312} }; 

	
	int (*pptr)[4] = sale;
	ptr = &sale[0][0];
	
	for (i = 0; i < 8; i++)
	{
		printf("\n address : %u sale %d = %d", ptr, i, *ptr);
		ptr++;
	}

	printf("\n배열 포인터 주소 : %u", pptr);
	printf("\n배열 포인터 + 1 주소 : %u", pptr + 1);
	printf("\n%d", pptr[1][1]);
	// printf("%d", ptr[1][1]);
	getchar();

}