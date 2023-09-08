#pragma once
#include <stdio.h>
#include <string.h>
/*
	성적 입력 프로그램 작성

구조체 작성
1-1. 학생
이름(unique), 나이, 학번

1-2. 성적
과목, 학점(학점 A B C D F)

학생 정보를 입력, 검색, 삭제, 수정 할 수 있어야 한다.
성적 정보를 입력, 검색, 삭제, 수정 할 수 있어야 한다.
학생 검색시 학생의 성적이 조회 같이 조회 되어야 한다.

모든 기능은 아래의 인터페이스를 만족해야 한다.
5-1. 1)입력, 2)검색, 3)수정, 4)삭제 5)검색 6)종료

5-2. 입력, 검색, 수정, 삭제는 연속적으로 이루어 져야 한다.

즉, 프로그램 기능이 한번 진행한 이후 끝나는 것이 아니라 계속적으로 진행 되어야 한다.

제한시간 3시간
*/
struct Student {
	char name[10];
	int age;
	int s_num;
	int score;
	struct Student* nextStudent;
};

char grade(int score) {
	if (score < 40) return 'F';
	else if (score < 50) return 'E';
	else if (score < 60) return 'D';
	else if (score < 70) return 'C';
	else if (score < 80) return 'B';
	else if (score < 90) return 'A';
	else {
		printf("다시 입력하세요\n");
		return 0;
	}
}

char menu(char* select) {
	scanf_s("%c", select, 1);
	getchar();
	return *select;
}

struct Student* createStudent(char* name, int age, int s_num, int score) {
	struct Student *header;
	strcpy_s(header->name, sizeof(header->name), name);
	header->age = age;
	header->s_num = s_num;
	header->score = score;
	header->nextStudent = NULL;
	return header;
}
struct Student* newStudent(struct Student* pre, char* name, int age, int s_num, int score) {
	struct Student *new;
	new->nextStudent=pre->nextStudent;
	strcpy_s(new->name, sizeof(new->name), name);
	new->age = age;
	new->s_num = s_num;
	new->score = score;
	struct Student* nextStudent = NULL;
	return new;
}
struct Student* nextStudent(struct Student* first) {
	struct Student* last=first;
	while (last->nextStudent == NULL){
		last = first->nextStudent;
	}
	return last;
}
