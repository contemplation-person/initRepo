#include <stdio.h>
int change_val_exam(int i); // 함수의 머리 부분을 맨 위로 올려주면 메인함수를 제일 위로 올릴 수 있음,프로토 타입;
int change_val(int* pi); // 함수의 오류를 걸러내줌.
int add_number(int* parr);
int maximum(int* arr);

void main() {
	int i = 0;
	printf_s("호출 이전의 i 값 : %d \n", i);

	change_val_exam(i);
	printf("호출 이후 i 값 : %d \n", i);

	printf("------------------\n");

	int pi=0;
	change_val(&pi);//call by address
	printf("함수 밖의 pi:%d\n", pi);

	printf("------------------\n");
	int arr[3];

	for ( i = 0; i < 3; i++) {
		scanf_s("%d", &arr[i]);
	}
	
	add_number(arr);
	for ( i = 0 ; i < 3;i++)	printf("%d ", arr[i]);
	printf("\n------------------\n");
	
	int num_max[10] = { 0, };
	
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &num_max[i]);
	}
	printf("%d", maximum(num_max));

}

int change_val_exam(int i) {
	i = 3;
	return 0;
}

int change_val(int* pi) {
	printf_s("함수 안에서 pi의 주소값 : %p\n", pi);
	printf_s("함수 안에서 pi의 값 : %d\n", *pi);

	printf_s("함수 안에서 변경 %d\n", *pi += 1);
	return 0;
}

int add_number(int* parr) {
	for (int i = 0; i < 3; i++) {
		parr[i]++;
	}
	return 0;
}

int maximum(int* arr) {
	int cnt;
	for (int i = 0; i < 10; i++) {
		if (i == 0) cnt = arr[0];
		if (cnt<arr[i]) cnt = arr[i];
	}
	return cnt;
}