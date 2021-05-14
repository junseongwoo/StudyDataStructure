#include <stdio.h>

// 노드 구조를 구조체로 정의
typedef struct node {
	int data;
	struct node* next;
}Node; 

// 첫번째 노드를 가리키는 헤드 노드 정의
typedef struct head {
	Node* head;         // 노드 가리킬수 있는 타입이 와야한다.
}headNode; 

// 헤드를 생성하는 함수
headNode* createHead(void)
{
	// head가 가리키는것이 첫번째 노드 
	// 메모리의 동적 할당 영역에서 헤드 노드 사이즈 만큼 할당하여 주소를 리턴
	headNode* h = (headNode*)malloc(sizeof(headNode)); 
	
	// 역참조 방지
	if (h != NULL)
	{
		// 구조체 변수이기 때문
		h->head = NULL;
	}

	return h;  // 동적 할당 받은 주소를  리턴 
}

// 구조체도 하나의 타입 
void preInsertNode(headNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	/*헤더가 처음 노드를 가리키고 있는 것을 
	newNode의 next에 집어 넣는 것 */
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = h->head;
		h->head = newNode;
	}
}

// 후위 삽입 함수 
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
		
		 /*무한 반복 했던 이유 : if문을 실행 시키고 빠져나오지 않고
		 계속 밑으로 실행 시켰기 때문에 while 문도 실행이 된것이다.
		 else or return 으로 빠져나와야한다.*/

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

// 출력 함수
void outputNode(headNode* h)
{
	Node* output = h->head;    // 맨 처음 노드 가리킴 

	if (h->head == NULL)
	{
		printf("노드가 없습니다.\n");
	}
	else 
	{
		while (output != NULL)     // 리스트가 있으면 반복
		{
			printf("%d\n", output->data);
			output = output->next; // 그 다음 노드 가리킴
		}
	}
	
}

// 노드 삭제 함수
void allDelNode(headNode* h)
{
	Node* del;

	while (h->head != NULL)  // head 부터 차례대로 없애기 
	{
		del = h->head;       // del에 처음 노드 연결 
		h->head = del->next; // head를 del 다음노드랑 연결 시키고 
		free(del);           // del 삭제 
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
	printf("%d을 찾았다.\n", n->data);

	selectDeleteNode(h, n);
	outputNode(h);

	return 0;
}