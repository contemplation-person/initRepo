#include <stdio.h>
#define square(x) x *x // #define 함수(인자) 치환할 것 // 컴파일 하기전에 계산.
//#define square(x) (x) *(x) // 이렇게 메크로를 만들면 3+1도 우리가 의도했던 것처럼 잘 작동함.
#define RADTODEG(x) (x)*57.295
//#define RADTODEG(x) ((x)*57.295) // 1/RADTODEG(5)가 정상출력.
#define PrintVariableName(var) printf(#var "\n");//define 전처리기에서 사용되는 #, 인자 앞에 #를 붙이면 이를 문자열로 바꿈.
#define AddName(x,y) x##y // 전처리문에서 사용가능한 ## 문자열을 하나로 이어주는 역할.
void main(int argc,char** argv) {
	printf("square(3) : %d \n", square(3));
	printf("square(3) : %d \n", square(3+1)); //3+1*3+1

	printf("5rad는 : %f 도\n", RADTODEG(5));
	printf("5rad는 : %f 도\n", 1/RADTODEG(5));

	int AddName(a,b);
	PrintVariableName(a); 
	ab = 3;
	printf("%d \n", ab);
}