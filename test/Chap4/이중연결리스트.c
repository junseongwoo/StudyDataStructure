#include <stdio.h>

typedef struct dlistnode {
	int data;
	struct dlistnode* next;
	struct dlistnode* prev;
}DListNode;

typedef struct {
	DListNode* head;
}HeadNode;

HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}

DListNode* createNode(int data)  
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}
	else {
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
}

void insertNode(HeadNode* phead, DListNode* preNode, DListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode;
	}
	else
	{
		newNode->next = preNode->next;
		preNode->next = newNode;
		newNode->prev = preNode;

		if (newNode->next !=NULL)
		{
			newNode->next->prev = newNode;
		}
	}
}

void printNode(HeadNode* h)
{
	DListNode* n;
	n = h->head;
	
	while (n != NULL)
	{
		printf("%d\n", n->data);
		n = n->next;
	}
}

void deleteNode(HeadNode* h, DListNode* del)
{
	// TODO : 3���� �� �߰� ���� ���� �� �ִ� -> �������� �ȉ� 
	//      : ��尡 2���� �� ������ ���� �������� ����
	
	DListNode* temp;
	if (del != NULL)
	{
		if (h->head == NULL)
		{
			return;
		}
		else if (del->next == NULL)
		{

		}
		else
		{
			del->prev->next = del->next; // ���� ��� ������ next = ���� ����� next �ּ� 
			del->next->prev = del->prev; // ���� ��� ������ prev = ���� ����� prev �ּ�
			free(del);
		}
	}
	else
	{
		return;
	}

	
}

int main(void)
{
	HeadNode* h;
	DListNode* a;
	DListNode* b;
	DListNode* c;

	h = createHead();
	a = createNode(5);
	b = createNode(10);
	//c = createNode(15);

	insertNode(h, NULL, a);
	insertNode(h, a, b);
	//insertNode(h, b, c);
	printNode(h);

	deleteNode(h, b);
	printNode(h);


	return 0;
}