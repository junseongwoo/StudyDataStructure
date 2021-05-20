#include <stdio.h>
#include <stdbool.h>

#define STACK_SZ		3

//#include <stdbool.h> 하면 밑에 정의는 필요 없음
//#define TRUE		1
//#define FALSE		2

int isEmpty();     // 공백 체크
int isFull();      // 포화 체크
void push(int);    // 스택에 입력
int pop();         // 스택에서 출력
int peek();		   // 맨위의 스택 확인
void printStack();

int stack[STACK_SZ];
int top = -1;
int main(void)
{
	push(10);
	push(11);
	push(12);
	printStack();
	return 0;
}

int isEmpty()
{
	if (top <= -1) return true;
	else return false;
}

int isFull()
{
	if (top >= STACK_SZ - 1) return true;
	else return false;
}

void push(int data)
{
	if (isFull())
	{
		printf("STACK overflow!!\n");
		return;
	}
	else {
		stack[++top] = data;
	}
}
int pop()
{
	if (isEmpty()) {
		printf("STACK unserflow!!\n");
		return;
	}
	else
	{
		return stack[top--];
	}
}

int peek()
{
	if(isEmpty())
	{
		printf("STACK unserflow!!\n");
		return;
	}
	else return stack[top];
}

void printStack()
{
	if (!isEmpty())
	{
		for (int i = 0; i <= top; i++)
		{
			printf("%d   ", stack[i]);
		}
	}
}