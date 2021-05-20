#include <stdio.h>

int main()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };


	return 0;
}

void insertionSort(int* pary, int sz)
{
	int i;
	int temp;
	for (i = 1; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (pary[i] < pary[i - 1])
			{
				temp = pary[i];
				pary[i] = pary[i - 1];
				pary[i - 1] = temp;
			}
		}
		printf("\n%d ´Ü°è : ", i);
		for (int k = 0; k < sz; k++)
		{
			printf("%d    ", pary[k]);
		}
		
	}
}
void pirnt(int* pary, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("");
	}
}