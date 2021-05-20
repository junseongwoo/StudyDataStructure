#include <stdio.h>
#include <stdbool.h>

#define SIZE 6

int isEmpty();
int isFull();
void enQueue(int);   // q에 삽입
int deQuere();     // q에서 제거

/*
 큐 구조 : rear에서는 삽입만 되고 front에서는 삭제만 되는 것
           First In - First Out

		  -------------------
  rear ->                       -> front
		  -------------------
*/


int rear = 0;      // 입구
int front = 0;     // 출구 
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
void enQueue(int data)   // q에 삽입
{
	if (isFull()) printf("Queue overflow!!\n");
	else
	{
		rear = rear % SIZE;
		queue[rear] = data;
		rear++;
	}
}
int deQuere()     // q에서 제거
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