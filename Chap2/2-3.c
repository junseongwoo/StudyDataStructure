#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	int i;
	int mul;



	while (1)
	{
		printf("\n�� ���� ����Ͻðڽ��ϱ�? : ");
		scanf("%d", &n);

		for (i = 0; i < 10; i++)
		{
			mul = n * i;
			printf("%d * %d = %d\n", n, i, mul);
		}

	}

	return 0;
}
