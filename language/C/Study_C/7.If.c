#include <stdio.h>

void main() {
	int i;
	printf_s("입력하고 싶은 숫자를 입력하세요.\n");
	scanf_s("%d", &i);

	if (i == 7) {
		printf_s("당신의 행운의 숫자 7을 입력했습니다.");
	}
	else if (!i/* 0이 아닌 값을 영으로 반환, i==0과 같은 의미 */) {
		printf_s("x/0는 할 수 없습니다.");
	}
	else {
		if (i > 20 && i<100) {
			printf_s("20보다 큰 수를 입력하셨습니다.");
		}
		printf_s("0에서 19 사이의 숫자 중 7을 제외한 나머지와 100 이상의 숫자입니다.\n");
		while (!!i/* i==1 따라서 true로 인식 */) {
			printf_s("%d", !!i);
			return 0;
		}
	}
}