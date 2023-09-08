#include	<stdio.h>

__inline int square(int a) { return a * a; }//일반 함수와 달리  메인 함수 내에서 작동.(함수처럼 작동하는 것이지 함수는 아님.)
/*
	컴파일러가 처리, 매크로에 비해 디버깅 편리, 메크로보다 인라인함수를 더 권장.
*/
__inline int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

void main() {
	printf("%d\n", square(3));
	printf("%d\n", square(3 + 1)); // 메크로와 달리 정상 작동.

	printf("3,2 중 최대값은 : %d", max(3, 2));

}