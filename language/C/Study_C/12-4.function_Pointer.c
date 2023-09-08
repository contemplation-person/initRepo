#include <stdio.h>

int max(int a, int b);
int donothing(int a, int b);
int self(int max);

void main() {
	int a=1, b=2;
	int (*pmax)(int, int); // 함수 포인터.
	pmax = max;// 주의 : &max는 틀린 대입;

	printf("max(a,b): %d\n", max(a, b));
	printf("max(a,b): %d\n", pmax(a, b));

	pmax = donothing;
	printf("%d", pmax(1,2));
	
	printf("\n\n\n");

	printf("%d", self(5));
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int donothing(int a, int b) {
	return 1;
}

/*
문제 : 자기 자신을 호출하는 함수를 이용해서 1 부터 특정한 수까지의 곱을 구하는 프로그램을 만들어보세요. (난이도 : 下)

다시 풀어 볼 것.

int self(int max) {
	int value;
	if (max <= 1) return 1;
	else {
		value = (max * (self(max - 1)));
		return value;
	}
}

*/