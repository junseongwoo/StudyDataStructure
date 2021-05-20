// 퀵 정렬 : 대표적인 분할 정복 알고리즘 // 
// 시간 복잡도는 가장 좋다. nlogn 
// 정렬이 되어 있지 않은 구조에서 사용하면 빠르다.
/*
	1. 원소들 중에서 pivot을 고른다.
	2. pivot을 기준으로 앞에는 작은 값, 뒤에는 큰 값들을 위치시킨다.(분할)
	3. 분할된 작은 리스트를 재귀적으로 동작 시킨다.(정복)
	4. 정렬된 작은 리스트들을 결합한다. (결합)
*/
#include <stdio.h>

void quickSort(int*, int, int);
int main()
{
	int ary[] = { 3, 6, 9, 1, 8, 6, 4, 2 };
	int size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, 0, size - 1);
	return 0;

}
void quickSort(int* pary, int left, int right)
{
	if (left >= right) return;

	int pivot = left;
	int lleft = pivot + 1;
	int lright = right;
	int temp;

	while (lleft <= lright) // lleft와 lright가 교체 될 때까지
	{
		while (pary[lleft] <= pary[pivot]) lleft++;
		// 감소되다 보면 배열 크기를 넘어가 크기가 감소 되기 때문에 오류가 발생 
		while (pary[lright] >= pary[pivot] && lright > left) lright--;

		if (lleft > lright)
		{
			temp = pary[lright];
			pary[lright] = pary[pivot];
			pary[pivot] = temp;
		}
		else
		{
			temp = pary[lright];
			pary[lright] = pary[lleft];
			pary[lleft] = temp;
		}
	}
	
	printf("\n");
	quickSort(pary, left, lright - 1);
	quickSort(pary, lright + 1, right);
}