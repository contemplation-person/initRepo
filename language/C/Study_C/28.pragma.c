#include <stdio.h>
#include "28.weird.h"
#pragma pack(1) // 구조체를 1byte단위로 정렬. pragma는 컴파일러 종속적 따라서 다른 컴파일러에서 작동하지 않을 수 있음.
#include "28.weird2.h"


void main() {
	struct Weird a;
	printf("size of a : %d \n", sizeof(a)); //4byte단위로 처리, 컴파일러는 4byte로 데이터를 보관하는 것이 용이, 이것을 "더블워드 경계에 놓여있다" 라고 함
}