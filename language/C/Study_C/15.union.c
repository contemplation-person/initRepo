#include <stdio.h>
union similar_st { // 잘 쓰이지 않음. 메모리를 공유하는 공유형.
	double a;// 리틀에디안 사용. 즉 뒤에서부터 공유함.
	int b;
	char c;
};
void main() {
	enum {zero,one,two,three,four};
	int enum_ = two;

	switch (enum_){
		case (one): printf("1출력\n"); break;
		case (two): printf("2출력\n"); break;
		case (three): printf("3출력\n"); break;
		case (four): printf("4출력\n"); break;
		default:
			printf("잘못출력\n");
			break;
	}	
	
	enum {zero5=5,one6,two3=3,three4,four5};
	enum_ = one6;// 6이 삽입
	enum_ = three4;// two를 3으로 정의했으므로 three4 = 4이다.

	switch (enum_){
		case (one): printf("1출력\n"); break;
		case (two): printf("2출력\n"); break;
		case (three): printf("3출력\n"); break;
		case (four): printf("4출력\n"); break;
		default:
			printf("잘못출력\n");
			break;
	}


}