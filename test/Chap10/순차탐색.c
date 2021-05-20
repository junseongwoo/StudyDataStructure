#include <stdio.h>

int Lsearch(int* pary, int size, int tg)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (tg == pary[i]) return i;
	}
	return -1;
}

int main()
{
	int index;

	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	index = LSearch(ary, size, 2);

	if (index == 1) 
	{
		pirntf("찾기 실패!!!\n");
	}
	else
	{
		printf("%d\n", index);
	}

	return 0;
}