#include <stdio.h>
#include "17.headerFile.h"// 전처리기 명령 : 컴파일 이전에 실행
char compare(char* str1, char *str2);

void main() {
	char str1[20];
	char str2[20];

	scanf_s("%s", str1,sizeof(str1));
	scanf_s("%s", str2, sizeof(str1));

	if (compare(str1, str2)) {
		printf("%s와 %s 는 같은 문장입니다. \n", str1, str2);
	}
	else {
		printf("%s와 %s 는 다른 문장입니다. \n", str1, str2);
	}

	int a = 0;
	test(&a);
	printf("%d", a);
}