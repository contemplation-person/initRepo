#include <stdio.h>
#include <stdlib.h>

void get_average(int** arr, int numStudent, int numSubject);

void main(int argc, int**argv) {
	int x, y;
	int** arr;

	printf("arr[x][y]\n");
	scanf_s("%d %d", &x, &y);
	arr = (int**)malloc(sizeof(int*) * x);//1차원 배열에 int 포인터를 삽입. 즉 포인터 배열;
	
	for (int i = 0; i < x; i++) {
		arr[i] = (int*)malloc(sizeof(int*) * y); // 포인터 배열에 메모리 공간 할당.
	}

	for (int i = 0; i < x; i++) {
		free(arr[i]);// 포인터 배열부터 free선언.
	}
	free(arr);// free 순서 중요!
	
	printf("\n-------------------------------\n");
	int sum = 0;
	int subject, student;

	printf("과목 수 : ");
	scanf_s("%d", &subject);
	printf("학생수 수 : ");
	scanf_s("%d", &student);

	arr = (int**)malloc(sizeof(int*) * subject);

	for (int i = 0; i < subject; i++) {
		arr[i] = (int*)malloc(sizeof(int) * student);
	}

	for (int i = 0; i < subject; i++) {
		printf("과목 %d 점수\n", i);
		for (int j = 0; j < student; j++) {
			printf("j학생의 %d의 점수 입력 :",i+1);
			scanf_s("%d", &arr[i][j]);
		}
		printf("점수는 \n");
		for (int j = 0; j < student; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	get_average(arr, student, subject);
	
	for (int i = 0; i < subject; i++) {
		free(arr[i]);
	}
	free(arr);

	//vidual studio에서 컴파일 되지 않음.
	/*
	printf("\n----------------------------------\n");
	int width, height;
	printf("행의 크기 ");
	scanf_s("%d", &width);
	printf("\n열의 크기 ");
	scanf_s("%d", &height);
	
	int(*arr)[width] = (int(*)[width])malloc(height * width * sizeof(int));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	*/

}

void get_average(int** arr, int numStudent, int numSubject) {
	int sum;
	for (int i = 0; i < numSubject; i++) {
		sum = 0;
		for (int j = 0; j < numStudent; j++) {
			sum += arr[i][j];
		}
		printf("과목 %d의 평균점수 : %d\n", i+1, sum / numStudent);
	}
}