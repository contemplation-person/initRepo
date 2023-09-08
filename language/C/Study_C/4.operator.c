#include <stdio.h>
void main() {
	int a, b;
	a = 10, b = 3;
	printf_s("a+b는 : %d\n", a + b);
	printf_s("a-b는 : %d\n", a - b);
	printf_s("a*b는 : %d\n", a * b);
	printf_s("a/b는 : %d\n", a / b);
	printf_s("a%%b는 : %d\n", a % b); // "%%" -> %
	
	double c = 3.0;
	printf_s("a/b는 : %f\n", a / c); //  자동 형변환, 묵시적 형변환
	printf_s("a/b는 : %f\n", a / (double)b); // 캐스팅, 명시적 형변환
	
	printf_s("%d\n", ++b); // 전위형
	printf_s("%d\n", b++); // 후위형
	printf_s("%d\n", b);
	b += 1; /* 이외에도 -=, /=, *= 가 있음. */
	printf_s("%d\n\n", b);

	/* 
	bit_operator 

	& 두 값 중 하나가 1이면 1출력     and
	| 두 값이 모두 맞으면 1출력       or
	^ 두 값이 다르면 1출력            xor
	~ 0이면 1, 1이면 0 출력
	<< 2칸 왼  쪽으로 당겨서 출력 (당겨진 칸은 0 삽입)
	>> 2칸 오른쪽으로 당겨서 출력 (당겨진 칸은 0 삽입)

	순서 : 산술 논리 (삼항) 대입 순
	*/
	
	


}