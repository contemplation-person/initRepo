#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct stackNode {
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top; //스택의 top 노드를 지정하기 위해 포인터 top 선언

int isEmpty() {
	if (top == NULL)return 1;
	else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
	element item;
	stackNode* temp = top;
	
	if (top == NULL) {
		printf("스택이 비었습니다.\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

// 스택의 top 원소를 검색하는 연산
element peek() {
	if (top == NULL) {
		printf("\n 스택이 비었습니다.\n");
		return 0;
	}
	else return (top->data);
}

// 스택의 원소를 순서대로 출력
void printStack() {
	stackNode* p = top;
	printf("\nstack [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

void main() {
	element item;
	top = NULL;
	printf("연결 스택 연산\n");
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack(); printf("\n");

	item = peek(); printStack();
	printf("peek = %d", item);
	item = pop();	printStack();
	printf("pop = %d", item);
	item = pop();	printStack();
	printf("pop = %d", item);

	printf("\n\n연결 스택\n장점 : 스택 크기 변경이 쉬움, 메모리 사용이 효율적\n단점 : 순차스택에 비해 어려움.");
	getchar();

}