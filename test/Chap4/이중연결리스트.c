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
		if (preNode == NULL)
		{
			phead->head->prev = newNode;
			newNode->next = phead->head;
			phead->head = newNode;
		}
		else 
		{
			preNode->next->prev = newNode;
			newNode->next = preNode->next;

			newNode->prev = preNode;
			preNode->next = newNode;

			if (preNode->next == NULL)
			{
				//todo 
			}
		}
	}
}

void printNode(HeadNode* h)
{
	DListNode* n;
	n = h->head;
	
	if (n == NULL)
	{
		printf("����Ʈ�� �����ϴ�.\n");
	}
	else
	{
		while (n != NULL)
		{
			printf("%d\n", n->data);
			n = n->next;
		}
	}
}

void deleteNode(HeadNode* h, DListNode* del)
{
	if (del != NULL)
	{
		if (h->head == NULL)
		{
			return;
		}
		else if (del->next == NULL) // del�� ������ ��� �� �� 
		{
			del->prev->next = del->next;
			free(del);
		}
		else if (h->head == del) // del�� �� ó�� ��� �� �� 
		{
			if (del->next == NULL)  // del�� �� ó���̰� ������ ��� �� �� 
			{
				h->head = NULL;
				free(del);
			}
			else
			{
				h->head = del->next;
				free(del);
			}
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

DListNode* findNode(HeadNode* phead, int data)
{
	DListNode* find = phead->head;

	while (find != NULL)
	{
		if (find->data == data)
		{
			return find;
		}
		else
		{
			find = find->next;
		}
	}
	return find;

}

int main(void)
{
	HeadNode* h;
	DListNode* n;

	DListNode* a;
	DListNode* b;
	DListNode* c;
	DListNode* d;


	h = createHead();
	a = createNode(5);
	//b = createNode(10);
	//c = createNode(15);
	//d = createNode(20);


	insertNode(h, NULL, a);
	//insertNode(h, NULL, b);
	//insertNode(h, a, c);
	//insertNode(h, c, d);
	printNode(h);
	//deleteNode(h, a);

	//printNode(h);

	/*n = findNode(h, 5);
	printf("-------ã�Ƽ� �߰�------\n");
	insertNode(h, n, c);
	printNode(h);

	printf("-------���� ����--------\n");
	n = findNode(h, 10);
	deleteNode(h, n);
	printNode(h);*/

	return 0;
}