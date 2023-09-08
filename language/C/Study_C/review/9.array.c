#include <stdio.h>

		
void main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int arr1[] = { 11,21,31 };
	printf_s("%d\n", arr[2]);
	//printf_s("%d\n", arr1[2]);

	int arr2[] = { 2, 10, 39, 21, 35, 23, 55 };
	for (int i = 0; i < sizeof(arr2) / 4; i++) {
		printf_s("%d ", arr2[i]);
	}
	printf_s("\n");

	/*
		소수 찾기 (나눌 수 있는 수가 1과 자기자신일 경우 소수)
		왜 컴파일이 안되는가....? && 효율적인 코드는 아님(개선 필요)

		int primeNum[1000] = { 0, };
		int cnt;
		for (int i = 1; i < sizeof(primeNum)/4+1 ; i++) {
			cnt = 0;
			for (int j = 1; j < i; j++) {
				if (i%j==0) cnt += i / j;
				if (cnt == 1 + i) primeNum[i-1] = i + 1;
			}
		}
		for (int i = 0; i < sizeof(primeNum)/4; i++) {
			if(primeNum[i] !=0) printf_s("%d ", primeNum[i]);
		}
	*/
	//문제1. 입력받는 학생들의 성적을 높은 순으로 정렬하는 프로그램을 만들어 보세요.
	int st_num[5] = { 0, };

	for (int i = 0; i < sizeof(st_num) / 4; i++) {
		scanf_s("%d", &st_num[i]);
	}
	printf("\n--------정렬전-----------\n");
	for (int i = 0; i < sizeof(st_num) / 4; i++) {
		printf_s("%d ", st_num[i]);
	}
	printf("\n");

	/* 선택정렬 */
	int temp = 0;

	for (int i = 0; i < sizeof(st_num) / 4; i++) {
		for (int j = 0; j < sizeof(st_num) / 4; j++) {
			printf_s("%d ", st_num[i]);
			if (st_num[i] > st_num[j]) {
				temp = st_num[i];
				st_num[i] = st_num[j];
				st_num[j] = temp;
			}
		}
	}

	printf("\n--------정렬후-----------\n");
	for (int i = 0; i < sizeof(st_num) / 4; i++) {
		printf_s("%d ", st_num[i]);
	}

}