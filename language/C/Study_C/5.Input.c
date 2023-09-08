#include <stdio.h>

void main() {
	char c = 'A';
	
	printf_s("%d, %c\n\n", c, c); // 아스키 코드 65, A

	double celsius;

	printf_s("섭씨 -> 화씨\n");
	printf_s("섭씨 온도를 입력\n");

	scanf_s("%lf"/* scanf의 경우 lf인지 f인지 명확하게 해야함. */, &celsius); // 키보드로 결과를 받아들이는 함수.
	printf_s("섭씨 %f, 화씨 %f\n", celsius, celsius * 9 / 5 + 32); //scanf & printf == 입출력함수
	
	short sh;
	long lo;
	scanf_s("%hd\n", &sh);
	scanf_s("%ld\n\n\n", &lo);
	printf_s("%d %ld\n\n", sh, lo);
	/* 허용된 범위 이상의 데이터를 집어넣는 것 == 버퍼 오버플로우 */
	
	//예제문제 (두개는 다르다.)
	printf_s("섭씨 %f, 화씨 %f\n", celsius, 9*celsius/5+32);
	printf_s("섭씨 %f, 화씨 %f\n", celsius, 9/5*celsius + 32);
	/* 
	이유 : celsius는 부동소수, 9와 5는 정수이다.
		   따라서 1번의 경우 나눗셈시 소수값까지 나오지만
				  2번의 경우 나눗셈시 몫(정수)이 먼저 출력 후 곱해지기 때문에 답이 달라진다.
		   해결방법 : 캐스팅, 또는 소수로 바꿔 묵시적 형변환을 한다.
	*/
	printf_s("\n섭씨 %f, 화씨 %f\n", celsius, 9.0/5*celsius + 32);
	printf_s("섭씨 %f, 화씨 %f\n", celsius, (double)9/5*celsius + 32);
}