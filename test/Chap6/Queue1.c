#include <stdio.h>
#include <stdbool.h>

#define SIZE 6

int isEmpty();
int isFull();
void enQueue(int);   // q�� ����
int deQuere();     // q���� ����

/*
 ť ���� : rear������ ���Ը� �ǰ� front������ ������ �Ǵ� ��
           First In - First Out

		  -------------------
  rear ->                       -> front
		  -------------------
*/


int rear = 0;      // �Ա�
int front = 0;     // �ⱸ 
int queue[SIZE];

int main()
{
	enQueue(10);
	enQueue(20);
	enQueue(30);
	enQueue(40);

	printf("%d\n", deQuere());

	return 0;
}

int isEmpty()
{
	if (rear == front) return true;
	else return false;
}
int isFull()
{
	if (front == (rear + 1) % SIZE) return true;
	else return false;
}
void enQueue(int data)   // q�� ����
{
	if (isFull()) printf("Queue overflow!!\n");
	else
	{
		rear = rear % SIZE;
		queue[rear] = data;
		rear++;
	}
}
int deQuere()     // q���� ����
{
	if (isEmpty())
	{
		printf("Queue overflow!!\n");
		return;
	}
	else
	{
		return queue[front++ % SIZE];
	}

	
}