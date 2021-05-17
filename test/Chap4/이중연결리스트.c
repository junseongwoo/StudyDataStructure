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
		printf("리스트가 없습니다.\n");
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
		else if (del->next == NULL) // del이 마지막 노드 일 때 
		{
			del->prev->next = del->next;
			free(del);
		}
		else if (h->head == del) // del이 맨 처음 노드 일 때 
		{
			if (del->next == NULL)  // del이 맨 처음이고 마지막 노드 일 때 
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
	printf("-------찾아서 추가------\n");
	insertNode(h, n, c);
	printNode(h);

	printf("-------삭제 이후--------\n");
	n = findNode(h, 10);
	deleteNode(h, n);
	printNode(h);*/

	return 0;
}