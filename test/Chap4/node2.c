#include <stdio.h>

typedef struct node
{
	int data;
	struct node* link;
}Node;

void addNode(Node* target, int data)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;            
	newNode->link = target->link;    // 다음 노드를 지정하는 것 

	target->link = newNode;          // 다음 노드에 새 노드를 저장 
}

void LastAddNode(Node* target, int data)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;

	Node* curr = target->link;

	while (curr->link != NULL)
		curr = curr->link; // 마지막 노드를 지정 
	curr->link = newNode;  // 새 노드를 마지막 노드 다음 노드로 지정
}

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node)); // 헤드 노드 생성

	head->link = NULL; 
	
	// 함수 호출
	addNode(head, 10); 
	addNode(head, 50);
	LastAddNode(head, 150);
	addNode(head, 70);
	LastAddNode(head, 100);

	Node* curr = head->link;

	// 주소 값으로 노드를 바꿀 수 있지만 그렇게 하지말것! 

	while (curr != NULL)               
	{
		printf("%d\n", curr->data);    
		curr = curr->link;     
		printf("%p\n", curr);
	}
	
	
	free(head);
	
	return 0;
}