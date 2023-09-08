#pragma once
/*
	팩토리얼	n! -> n*(n-1)! -> n*n(n-1)*(n-2)! .....
*/

unsigned long int factorial(int num) {
	if (num <= 1) return 1;
	else return (num * factorial(num - 1));
}

// n = 하노이탑 갯수, start = 시작지점, work = 중간 작업봉, target = 최종 지점; 
void hanoi(int n, int start, int work, int target) {
	if (n == 1)	printf("원판 %d를 %c -> %c 로 이동\n", n, start,target);
	else {
		hanoi(n - 1, start, target, work);
		printf("원판 %d를 %c -> %c 로 이동\n", n,start,target);
		hanoi(n - 1, work, start, target);
	}
}