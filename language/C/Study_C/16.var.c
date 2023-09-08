#include <stdio.h>
void function();

int global; // 전역 변수. 데이터 영역에 할당, 전역변수는 정의시 0으로 초기화.
int how_many_called = 0;

void main() {
	int a = 3;
	global = 10;
	{	// {} 하나의 지역
		int a = 4;
		printf("%d\n", a);
	}
		function();
	printf("%d\n", a);
	printf("%d\n", global);

	printf("\n");
	function();
	function();
	function();
	function();
}

void function() {
	int a = 2; // 지역변수
	global++;
	how_many_called++;
	printf("%d\n", how_many_called);
}