
#include <stdio.h>
#include <stdlib.h>
#include "source.h"
/*
	성적 입력 프로그램 작성

구조체 작성
1-1. 학생

이름(unique), 나이, 학번

1-2. 성적
과목, 성적을 입력하면 학점출력(학점 A B C D F)

학생 정보를 입력, 검색, 삭제, 수정 할 수 있어야 한다.
성적 정보를 입력, 검색, 삭제, 수정 할 수 있어야 한다.
학생 검색시 학생의 성적이 조회 같이 조회 되어야 한다.

모든 기능은 아래의 인터페이스를 만족해야 한다.
5-1. 1)입력, 2)검색, 3)수정, 4)삭제 5)검색 6)종료

5-2. 입력, 검색, 수정, 삭제는 연속적으로 이루어 져야 한다.

즉, 프로그램 기능이 한번 진행한 이후 끝나는 것이 아니라 계속적으로 진행 되어야 한다.

제한시간 3시간
*/


int main() {
	char select = 0;
	int age, s_num, score, flag = 0;
	char name[10];
	struct Student* first;

	while (1) {
		printf("메뉴: 1)입력, 2)검색, 3)수정, 4)삭제  5)종료\n");
		menu(&select);
		switch (select-48) {
		case(1): {
			printf_s("이름, 나이, 학번, 점수를 입력해주세요\n");
			scanf_s("%s %d %d %d", name,sizeof(name), &age, &s_num, &score);
			if (flag == 0) first = createStudent(name, age, s_num, score);
			else newStudent(nextStudent(first), name, age, s_num, score);
			printf("%s %d %d %d\n", nextStudent(first)->name, nextStudent(first)->age, nextStudent(first)->s_num, nextStudent(first)->score);
			flag++;
			break; 
		}
		case(2): break;
		case(3): break;
		case(4): break;
		default: return 0; 

		}
	}
}
		
