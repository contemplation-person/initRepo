#include <stdio.h>

/*
	어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
	등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.
	N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.

	첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

	첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.

	1~99까지는 비교대상이 없으므로 그냥 한수 취급,
	n+(n-1)d;가 연속으로 나열될 때 한수 취급,

	1, 1, 1 한수
	1, 2, 4 한수
	1, 3, 6 한수 ....

	1. 1~99내의 수이면 한수의 숫자는 그대로
	2. 100부터 가장 큰 자리의 숫자를 a으로 취급, 각 자리를 n으로 취급, d를 공차로 정의
	3. 숫자와 숫자를 비교한 값이 같으면 1 아니면 0 출력
*/
int under100(int num);
int check(int num);
//int ap(int a, int n, int d);

int main() {
	int num, cnt = 0;
	scanf_s("%d", &num);

	printf("%d", check(num));


	return 0;
}

int under100(int num) {
	int cnt = 0;
	for (int i = 1; i <= num; i++) cnt += 1;
	return cnt;
}

int under1000(int num) {
	int d = (num / 10 % 10) - num / 100;
	if (num % 100 % 10 == num / 100 + 2 * d) {
		return 1;
	}
	return 0;
}

int check(int num) {
	int cnt = 0;
	if (num < 100) {
		cnt = under100(num);
	}
	else if (num < 1000) {
		cnt = 99;
		for (int i = 100; i <= num; i++) {
			cnt += under1000(i);
		}
		//printf("%d", cnt);
	}
	else {
		cnt = 144;
	}
	return cnt;
}

int ap(int a, int n, int d) {
	return (a + (n - 1) * d);
}
