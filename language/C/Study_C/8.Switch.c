#include <stdio.h>

void main() {
	int input;
	printf_s("마이펫\n");
	printf_s("무엇을 하실 것인지 입력하세요.\n");
	printf_s("1. 밥주기\n");
	printf_s("2. 씻기기\n");
	printf_s("3. 재우기\n");
	scanf_s("%d", &input);
	
	switch (input) {
		case 1: printf_s("냠냠"); break;
		case 2: printf_s("와으르르"); break;
		case 3: printf_s("우걱우걱"); break;
		default: printf_s("명령을 잘 못 입력왈"); break;
	}
}