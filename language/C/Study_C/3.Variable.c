#include <stdio.h>

void main() {
	int a; 
	a = 127;
	printf_s("a 값은 %d\n", a);
	printf_s("a 값은 %d 진수로 %o\n", 8, a);
	printf_s("a 값은 %d 진수로 %d\n", 10, a);
	printf_s("a 값은 %d 진수로 %x\n", 16, a);

	float f = 3.141592f;
	double d = 3.151592;
	printf_s("%f\n", f);
	printf_s("%f\n\n", d);
	/*
	unsigned와 그냥의 차이는 0을 기점으로 "-반으로 나눈 수 ~ 0 ~ 반으로 나눈 수-1"이다
	
	char  : 1byte | unsigned char    | 0~255 (C에서만 해당, 자바는 2byte)
	int   : 4byte | unsigned int     | 0~4,294,967,295                         * 기본형
	long  : 8byte | unsigned long    | 1.84*10^19
	float : 4byte |                  | 엄청 큼. 정밀도 6~7정도
	double: 8byte |                  | 엄청 큼. 정밀도  15정도                 * 기본형
	*/

	/* printf_s형식 */
	printf_s("a: %5d\n", a);      // 5자리로 맞춰라, 넘길시 그대로 출력 
	printf_s("f: %.2f\n", f);     // 소수점 2째자리만 출력
	printf_s("d: %6.2f\n", d);    // .점 이하 2자리 & 6개의 숫자 출력 (.은 포함안함)

	/*
	변수 선언 주의사항

	1abc -> 맨 앞의 숫자 금지
	@#a  -> 무조건 숫자, 영어, _로 구성할 것 (한글 가능이나 안씀)
	a bc -> 띄어쓰기 금지
	int  -> 예약어 사용 금지
	a!=A -> 대소문자 구분.
	
	참고 : 좋은 변수 선언을 하려면 한가지 방식으로 선언하자 ex) appleMac || apple_mac
	*/
}