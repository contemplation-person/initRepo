#include <stdio.h>

void main() {
	for (int i = 0; i < 20; i++) {
		printf_s("%d\n", i);
	}
	int i = 0;

	for (; ; ) {
		printf_s("항상 true\n");
		if (i++ == 5) {
			break;
		}
	}

	for (;;i--) {
		if (i == 2) { continue; }
		else if (i == 0) break;
		printf_s("%d\n", i);
	}

	while (i < 5) {
		i++;
		printf_s("false 면 정지\n");
	}

	do {// 일단 실행.
		printf_s("%d\n", i);
	} while (0); // 0이 false

	printf_s("__________________연습문제___________________");
							/* 연습문제 */

	printf_s("문제 1 (난이도 : 下)\n");
	printf_s("1000 이하의 3 또는 5 의 배수인 자연수들의 합을 구한다.\n");
	
	int cnt=0;
	for (int i = 1000; i > 0; i--) {
		if (i % 3 == 0 || i % 5 == 0) {
			//printf_s("%d\n", i);
			cnt += i;
		}
	}
	printf_s("1번 문제 답은? %d\n", cnt);
	
	printf_s("\n-----------------------\n");

	printf_s("문제 2 (난이도 : 下)\n");
	printf_s("사용자로 부터 N 값을 입력 받고 1 부터 N 까지의 곱을 출력한다.\nn값을 입력해주세요. ");

	int N;
	cnt = 1;
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		cnt *= i;
	}
	printf_s("답: %d\n", cnt);
/*
	printf_s("\n-----------------------\n");

	printf_s("문제 3 (난이도 : 中)\n");
	printf_s("1000000 이하의 피보나치 수열 ( N 번째 항이 N - 1 번째 항과 N - 2 번째 항으로 표현되는 수열, 시작은 1,1,2,3,5,8,...) 의 짝수 항들의 합을 구한다.\n");

	cnt = 1;
	int temp1=1,temp2=1, temp3=0;
	for (int i = 0; i < 3; i++) {
		if (i%2 ==0) cnt += temp3;
		if (i % 2 == 0) {
			temp1 = temp3;
		} else {
			temp2 = temp3;
		}
		temp3 = temp1 + temp2;
		printf_s("%d ", temp3);
	}
		printf_s("답은 : %d\n", cnt);
*/
}