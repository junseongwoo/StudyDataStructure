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
	newNode->link = target->link;    // ���� ��带 �����ϴ� �� 

	target->link = newNode;          // ���� ��忡 �� ��带 ���� 
}

void LastAddNode(Node* target, int data)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;

	Node* curr = target->link;

	while (curr->link != NULL)
		curr = curr->link; // ������ ��带 ���� 
	curr->link = newNode;  // �� ��带 ������ ��� ���� ���� ����
}

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node)); // ��� ��� ����

	head->link = NULL; 
	
	// �Լ� ȣ��
	addNode(head, 10); 
	addNode(head, 50);
	LastAddNode(head, 150);
	addNode(head, 70);
	LastAddNode(head, 100);

	Node* curr = head->link;

	// �ּ� ������ ��带 �ٲ� �� ������ �׷��� ��������! 

	while (curr != NULL)               
	{
		printf("%d\n", curr->data);    
		curr = curr->link;     
		printf("%p\n", curr);
	}
	
	
	free(head);
	
	return 0;
}