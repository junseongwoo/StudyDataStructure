// �� ���� : ��ǥ���� ���� ���� �˰��� // 
// �ð� ���⵵�� ���� ����. nlogn 
// ������ �Ǿ� ���� ���� �������� ����ϸ� ������.
/*
	1. ���ҵ� �߿��� pivot�� ����.
	2. pivot�� �������� �տ��� ���� ��, �ڿ��� ū ������ ��ġ��Ų��.(����)
	3. ���ҵ� ���� ����Ʈ�� ��������� ���� ��Ų��.(����)
	4. ���ĵ� ���� ����Ʈ���� �����Ѵ�. (����)
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

	while (lleft <= lright) // lleft�� lright�� ��ü �� ������
	{
		while (pary[lleft] <= pary[pivot]) lleft++;
		// ���ҵǴ� ���� �迭 ũ�⸦ �Ѿ ũ�Ⱑ ���� �Ǳ� ������ ������ �߻� 
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