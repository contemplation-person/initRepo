#include <stdio.h>
int fibonacci(int n);

void main() {
	int num;
	scanf_s("%d", &num);
	printf("%d", fibonacci(num));
}

int fibonacci(int n) {
	if (n < 0) {
		return 0;
	} else if (n == 1) {
		return n;
	}

	int temp = 0;
	int temp2 = 1;
	int temp3;
	for (int i = 2; i <= n; i++) {
		temp3 = temp + temp2;
		temp = temp2;
		temp2 = temp3;
	}
	return temp3;
}