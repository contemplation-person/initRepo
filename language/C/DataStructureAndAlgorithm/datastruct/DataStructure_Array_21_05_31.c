#include <stdio.h>

void main() {
	char student[2][3][20];
	for (int i = 0; i < 2; i++) {
		printf("학생 %d의 이름 :", i + 1);
		gets(student[i][0]);

		printf("학생 %d의 학과 :", i + 1);
		gets(student[i][1]);

		printf("학생 %d의 학번 :", i + 1);
		gets(student[i][2]);
	}

	for (int i = 0; i < 2; i++) {
		printf("\n\n학생 %d", i + 1);
		for (int j = 0; j < 3; j++) {
			printf("\n\t");
			for (int k = 0; k < student[i][j][k] != '\0'; k++) {
				printf("%c", student[i][j][k]);
			}
		}
	}
}