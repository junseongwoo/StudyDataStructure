#include <stdio.h>

// ��� ������ ����ü�� ����
typedef struct node {
	int data;
	struct node* next;
}Node; 

// ù��° ��带 ����Ű�� ��� ��� ����
typedef struct head {
	Node* head;         // ��� ����ų�� �ִ� Ÿ���� �;��Ѵ�.
}headNode; 

// ��带 �����ϴ� �Լ�
headNode* createHead(void)
{
	// head�� ����Ű�°��� ù��° ��� 
	// �޸��� ���� �Ҵ� �������� ��� ��� ������ ��ŭ �Ҵ��Ͽ� �ּҸ� ����
	headNode* h = (headNode*)malloc(sizeof(headNode)); 
	
	// ������ ����
	if (h != NULL)
	{
		// ����ü �����̱� ����
		h->head = NULL;
	}

	return h;  // ���� �Ҵ� ���� �ּҸ�  ���� 
}

// ����ü�� �ϳ��� Ÿ�� 
void preInsertNode(headNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	/*����� ó�� ��带 ����Ű�� �ִ� ���� 
	newNode�� next�� ���� �ִ� �� */
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = h->head;
		h->head = newNode;
	}
}

// ���� ���� �Լ� 
void rearInsertNode(headNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* rear;
	if (newNode != NULL)
	{
		newNode->next = NULL;
		newNode->data = data;
		if (h->head == NULL)     
		{
			h->head = newNode;
		}
		
		 /*���� �ݺ� �ߴ� ���� : if���� ���� ��Ű�� ���������� �ʰ�
		 ��� ������ ���� ���ױ� ������ while ���� ������ �Ȱ��̴�.
		 else or return ���� �������;��Ѵ�.*/

		else  
		{
			rear = h->head;
			while (rear->next != NULL)
			{
				rear = rear->next;
			}

			rear->next = newNode;
		}
	}
	
}

// ��� �Լ�
void outputNode(headNode* h)
{
	Node* output = h->head;    // �� ó�� ��� ����Ŵ 

	while (output != NULL)     // ����Ʈ�� ������ �ݺ�
	{
		printf("%d\n", output->data);
		output = output->next; // �� ���� ��� ����Ŵ
	}
}

int main(void)
{
	headNode* h;
	h = createHead();

	//preInsertNode(h, 10);
	//rearInsertNode(h, 20);
	preInsertNode(h, 30);
	rearInsertNode(h, 40);
	outputNode(h);

	// todo free(h) ���� �� �ǰ� ����� 
	free(h);
	return 0;
}