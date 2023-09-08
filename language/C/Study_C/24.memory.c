#include <stdio.h>
#include <string.h>

void main() {
	char str[50] = { "I love Chewing C hahaha" };
	char str2[50];
	char str3[50];

	memcpy(str2, str, strlen(str) + 1); // 문자열 뒤의 쓰레기 값 때문에 경고 출력.
	memcpy(str3, "hello", 6); // 메모리의 특정한 부분을 다른 메모리 영역에 복사.

	printf("%s \n", str);
	printf("%s \n", str2);
	printf("%s \n", str3);

	printf("\n-------------------------------\n");
	printf("%s \n", str);
	memmove(str + 23, str + 17, 6);
	memmove(str + 1, str + 17, 6);
	printf("%s\n", str);//memcpy와 달리 메모리 공간이 겹쳐도 괜찮음

	printf("%d\n",memcmp(str, str2, 16));//두 메모리의 원하는 만큼 비교. 맞으면 0 아니면 0이 아닌 수 리턴.
}