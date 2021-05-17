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
		printf("메모리 할당 실패\n");
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
	// TODO : 3개일 때 중간 노드는 지울 수 있다 -> 나머지는 안됌 
	//      : 노드가 2개일 때 마지막 노드는 지워지지 않음
	
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
			del->prev->next = del->next; // 지울 노드 이전의 next = 지울 노드의 next 주소 
			del->next->prev = del->prev; // 지울 노드 다음의 prev = 지울 노드의 prev 주소
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