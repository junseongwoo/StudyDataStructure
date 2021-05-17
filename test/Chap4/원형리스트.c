#include <stdio.h>

typedef struct listnode {  // 노드 생성 구조체 
	int data;
	struct listnode* link;
}ListNode;

typedef struct {
	ListNode* head;
}HeadNode;

HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)
	{
		h->head = NULL;
	}
	return h;
}

ListNode* createNode(HeadNode* phead, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("메모리 할당 실패!!");
		return;
	}
	else
	{
		newNode->data = data;
		newNode->link = NULL;
		return newNode;
	}
}

void printNode(HeadNode* h)
{
	ListNode* n;
	n = h->head;
	if (h == NULL)
	{
		return;
	}
	do 
	{
		n = n->link;           
		printf("%d -> ", n->data);   
	} 
	while (n != h->head);
}

void insertFirstNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode;
		newNode->link = newNode;
	}
	else
	{
		/*phead->head->link = newNode;
		newNode->link = phead->head;
		phead->head = newNode;*/

		newNode->link = phead->head->link;
		phead->head->link = newNode;
	}
}

void insertLastNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode;
		newNode->link = newNode;
	}
	else 
	{
		newNode->link = phead->head->link;
		phead->head->link = newNode;
		phead->head = newNode;
	}
}

int main()
{
	HeadNode* h = createHead();

	ListNode* a = createNode(h, 1);
	ListNode* b = createNode(h, 2);
	ListNode* c = createNode(h, 3);
	ListNode* d = createNode(h, 4);
	ListNode* e = createNode(h, 5);


	insertFirstNode(h, b);
	insertFirstNode(h, a);
	insertLastNode(h, c);
	insertLastNode(h, d);
	insertFirstNode(h, e);

	printNode(h);

	return 0;
}