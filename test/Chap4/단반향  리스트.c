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

	if (h->head == NULL)
	{
		printf("��尡 �����ϴ�.\n");
	}
	else 
	{
		while (output != NULL)     // ����Ʈ�� ������ �ݺ�
		{
			printf("%d\n", output->data);
			output = output->next; // �� ���� ��� ����Ŵ
		}
	}
	
}

// ��� ���� �Լ�
void allDelNode(headNode* h)
{
	Node* del;

	while (h->head != NULL)  // head ���� ���ʴ�� ���ֱ� 
	{
		del = h->head;       // del�� ó�� ��� ���� 
		h->head = del->next; // head�� del �������� ���� ��Ű�� 
		free(del);           // del ���� 
		del = NULL;
	}
}

Node* searchNode(headNode* h, int data)
{
	Node* s = h->head;

	while (s != NULL)
	{
		if (s->data == data)
		{
			return s;
		}
		else s = s->next;
	}
	return s;
}

void selectDeleteNode(headNode* h, Node* n)
{
	Node* del;

	if (h->head->next == NULL)
	{
		free(h->head);
		h->head = NULL;
		return;
	}
	else if (n == NULL)
	{
		return;
	}
	else
	{
		del = h->head;
		while (del->next != n)
		{
			del = del->next;
		}

		del->next = n->next;
		free(n);
	}
}

int main(void)
{
	headNode* h;
	Node* n;
	h = createHead();

	preInsertNode(h, 10);
	/*preInsertNode(h, 20);
	preInsertNode(h, 30);
	rearInsertNode(h, 40);*/
	outputNode(h);

	n = searchNode(h, 40);
	printf("%d�� ã�Ҵ�.\n", n->data);

	selectDeleteNode(h, n);
	outputNode(h);

	return 0;
}