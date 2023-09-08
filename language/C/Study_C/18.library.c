#include<stdio.h> 
#include<string.h> // strcpy_s, strcmp와 같은 string 함수를 모아놓음.
#define VAR 10 // VAR  == 10 과 동일.
#define A

void main() {
	char str1[20] = { "hi" };
	char str2[20] = { "hello" };

	strcpy_s(str1, sizeof(str1), str2);  // strcpy_s(복사 변수, 사이즈, 복사할 문자열);

	printf("%s\n", str1);
	
	if (!strcmp(str1, str2)) { // strcmp : 두 문자열이 같으면 0 반환, 아니면 1반환;
		printf("두갠 같다");
	}
	else {
		printf("두갠 틀려");
	}

	printf("\n----------------------\n");
	char arr[VAR] = { "hi" };
	printf("%s\n", arr);
	
	printf("\n----------------------\n");
#ifdef A  // (매크로 이름)이 정의되었다면 이 부분이 코드에 포함되고 그렇지 않다면 코드에 포함되지 않는다.
	printf("AAAAA\n");
#endif
#ifdef B
	printf("BBBB\n");
#endif

}