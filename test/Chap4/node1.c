#include <stdio.h>

typedef struct node {
	int data;                  // data 멤버
	struct node* link;         // 다음 노드의 주소를 저장할 멤버
}Node;

int main(void)
{
	int i = 1;
	Node* head = (Node*)malloc(sizeof(Node)); // 헤더노드 생성
	Node* node1 = malloc(sizeof(Node)); // 노드 생성
	Node* node2 = malloc(sizeof(Node)); // 노드 생성
	Node* node3 = malloc(sizeof(Node)); // 노드 생성
	Node* node4 = malloc(sizeof(Node)); // 노드 생성


	if (node1 == NULL) return;
	node1->data = 10;
	node1->link = NULL;
	head->link = node1;         // 헤더노드에 첫번째 노드의 주소값을 넣음

	if (node2 == NULL) return;
	node2->data = 20;
	node2->link = NULL;
	node1->link = node2;        // node1의 링크값에 node2의 주소 값을 넣음
	
	node3->data = 30;
	node3->link = NULL;
	node2->link = node3;

	node4->data = 40;
	node4->link = NULL;
	node3->link = node4;
	

	Node* curr = head->link;
	while (curr != NULL) {
		printf("%d 번째 노드 데이터 : %d\n",i, curr->data);
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