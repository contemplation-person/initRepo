#include <stdio.h>

void main() {
	int i;
	char string1[20] = "Dreams come true!", string2[20], * ptr1, * ptr2;

	ptr1 = string1;
	printf("string1 : %s\nptr1 :%s\n\n", string1, ptr1);

	printf("%s\n", ptr1 + 7); //ptr1의 char* 주소값인 7번째 뒤에서부터 NULL값까지 읽어온다.

	ptr2 = &string1[7]; // 역시 같은 원리로 char* +7 의 주소값을 ptr2에 넣었다.
	printf("%s\n", ptr2);

	for (i = 0; i < 20; i++) {
		string2[i] = *(ptr1 + i);
	}

	printf("\n%s", string2);
}