#include <stdio.h>
#include <stdlib.h>
/*
	메모리 동적(가변)할당.

	malloc은 heap에 할당.
*/
void main() {
	int sizeOfArr;
	int* arr;
	
	printf("만들 배열의 수");
	scanf_s("%d", &sizeOfArr);

	arr = (int*)malloc(sizeof(int) * sizeOfArr);//메모리를 할당해줌.

	free(arr);// 사용하지 않는 메모리를 먹게 됨

	printf("\n------------------------------------\n");
	int student;// 학생수
	int input;
	int* score;// 학생들의 수학점수 변수
	int sum = 0;//총점

	printf("학생수: ");
	scanf_s("%d", &student);

	score = (int*)malloc(sizeof(int) * student);
	if (score != NULL) { // 2019에서는 할당 공간이 null일 경우를 대비해 경고 표시를 해줌.

		for (int i = 0; i < student; i++) {
			printf("학생 점수 : ");
			scanf_s("%d", &score[i]);
		}

		for (int i = 0; i < student; i++) {
			sum += score[i];
		}
	free(score);
	} else return 1;

	printf("%d\n", sum);
}