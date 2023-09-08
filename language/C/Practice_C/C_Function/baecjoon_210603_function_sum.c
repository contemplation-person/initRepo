#include <stdio.h>
#include <stdlib.h>
/*
		첫째 줄에는 테스트 케이스의 개수 tcase가 주어진다.
		둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다.
		점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

		각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.

		1. 테스트 케이스 갯수를 받는다.
		2. 학생 수를 받는다.
		3. 학생 수 크기만큼의 동적 배열을 만든다.
		4. 동적배열에 점수를 받는다.
		5. 평균을 출력한다. ( 함수로 구현한다.)
		6. 평균을 넘는 학생의 비율을 출력한다. (함수로 구현)

		사실 함수로 구현할 필요는 없음.
*/
double avg(int student, double* score);
double overavg(double* score, double avg, int student);

int main() {
	int tCase,flag=0, student;
	double* score;
	scanf_s("%d", &tCase);

	//tCase = 1;// 검사

	while (flag < tCase) {
		scanf_s("%d", &student);
		//student = 3; //검사

		score = (double*)malloc(student * sizeof(double));

		for (int i = 0; i < student; i++) {
			scanf_s("%lf", score+i);
		}
		//printf("%lf", avg(student, score));
		printf("%.3lf%%\n",overavg(score, avg(student, score), student));
		overavg(score, avg(student, score), student);
		
		free(score);
		flag++;
	}

	return 0;
}

double avg(int student, double * score) {
	double total=0;

	for (int i = 0; i < student;i++) {
		total += score[i];
	}

	return total / student;

}

double overavg(double* score, double avg, int student) {
	double cnt=0;
	for (int i = 0; i < student; i++) {
		if (avg < score[i]) cnt += 1;
	}
	return cnt / student*100;
}