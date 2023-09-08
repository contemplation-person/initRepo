#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1; // 스택 초기화

// 스택이 공백인지 검사
int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

// 스택이 포화상태인지 확인하는 연산
int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(int item) {
	if (isFull()) {// 스택 포화상태인경우
		printf("스택이 포화상태입니다.\n");
	}
	else stack[++top] = item;    
}

// stack의 top에서 원소를 삭제하는 연산
int pop() {
	if (isEmpty()) {
		printf("스택이 비었습니다.\n");
		return 0;
	}
	else return stack[top--];
}

// 스택의 top 원소를 검색하는 연산
int peek() {
	if (isEmpty()) {
		printf("스택이 비었습니다.");
		exit(1);
	}
	else return stack[top];
}

// 스택의 원소를 출력하는 연산
void printStack() {
	printf("\nstack { ");
	for (int i = 0; i <= top; i++) printf("%d ", stack[i]);
	printf("} ");
}

void main() {
	int item;
	printf("순차 스택 연산\n");
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

	printf("\n\n순차 스택\n장점 : 쉽게 선언 가능\n단점 : 스택 크기 변경이 어려움, 배열을 할당하기 때문에 메모리 사용의 효율성이 떨어짐.");
	getchar();
}