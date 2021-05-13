#include <stdio.h>

typedef struct node {
	int data;                  // data ���
	struct node* link;         // ���� ����� �ּҸ� ������ ���
}Node;

int main(void)
{
	int i = 1;
	Node* head = (Node*)malloc(sizeof(Node)); // ������ ����
	Node* node1 = malloc(sizeof(Node)); // ��� ����
	Node* node2 = malloc(sizeof(Node)); // ��� ����
	Node* node3 = malloc(sizeof(Node)); // ��� ����
	Node* node4 = malloc(sizeof(Node)); // ��� ����


	if (node1 == NULL) return;
	node1->data = 10;
	node1->link = NULL;
	head->link = node1;         // �����忡 ù��° ����� �ּҰ��� ����

	if (node2 == NULL) return;
	node2->data = 20;
	node2->link = NULL;
	node1->link = node2;        // node1�� ��ũ���� node2�� �ּ� ���� ����
	
	node3->data = 30;
	node3->link = NULL;
	node2->link = node3;

	node4->data = 40;
	node4->link = NULL;
	node3->link = node4;
	

	Node* curr = head->link;
	while (curr != NULL) {
		printf("%d ��° ��� ������ : %d\n",i, curr->data);
		curr = curr->link;
		i++;
	}

	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(head);

	return 0;
}