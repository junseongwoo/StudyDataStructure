//선택정렬 : 0번방을 최소값이라고 가정하고 나머지 원소들과 비교하여 교체한다.
#include <stdio.h>

void insertionSort(int*, int);
int main()
{
	int ary[] = { 1,2,5,6,3,4,7,8,9};
	int size = sizeof(ary) / sizeof(ary[0]);
	insertionSort(ary, size);

	return 0;
}
void insertionSort(int* pary, int size)
{
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i+1; j < size; j++)
		{
			if (pary[min] > pary[j]) min = j;
		}
		temp = pary[min];
		pary[min] = pary[i];
		pary[i] = temp;

		printf("\n%d 단계 ", i +1);
		for (int k = 0; k < size; k++)
		{
			printf("%d  ", pary[k]);
		}
	}
}