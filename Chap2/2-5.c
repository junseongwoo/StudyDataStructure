#include <stdio.h>

int main(void)
{
	int i, length = 0;
	char str[50];
	printf("\n���ڿ��� �Է��ϼ��� : ");
	gets(str);  // ���ڿ� �Է� �Լ�
	printf("\n�Էµ� ���ڿ��� \n \"");
	for (i = 0; str[i]; i++)
	{
		printf("%c", str[i]);
		length += 1;
	}
	printf("\" \n�Դϴ�.");
	printf("\n\n�Էµ� ���ڿ��� ���� = %d \n", length);

	getchar();
	return 0;
}