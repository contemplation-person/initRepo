#include <stdio.h>
int pswap(int** pa, int** pb);
int add1_element(int(*arr)[2], int row);
void multi(int arr[][3][2]);

void main() {
	int a=1, b=2;
	int* pa, *pb;

	pa = &a;
	pb = &b;

	//printf("%p %p\n", pa, pb);

	pswap(&pa, &pb);

	//printf("%p %p", pa, pb);
	printf("%d %d\n", *pa, *pb);

	printf("\n---------------------\n");
	int arr2[3][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &arr2[i][j]);
		}
	}

	add1_element(arr2,3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", arr2[i][j]);
		}
	}
	printf("\n---------------------\n");

}


int pswap(int** ppa, int** ppb) {
	
	int* temp = *ppa;
	printf("%p %p\n", temp,ppa);
	*ppa = *ppb;
	*ppb = temp;// 주소값을 swap;

	return 0;
}
int add1_element(int(*arr)[2]/* int arr[][2] */, int row) {
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 2; j++) {
			arr[i][j]++;
		}
	}
	return 0;
}
void multi(int arr[][3][2]/* int(*arr)[3][2] */) {
	arr[0][0][0] = 1;// 이것도 가능
}