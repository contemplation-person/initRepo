#pragma once
/*
	보통 헤더파일에 저장하는 요소
	1. 전역변수
	2. 구조체, 공용체, 열거체
	3. 함수의 원형
	4. 일부 특정한 함수 (인라인함수) // 4,5는 뒤에 설명.
	5. 메크로
*/

enum { male, female };

struct Human {
	char name[20];
	int age;
	int gender;
};

struct Human Create_Human(char* name, int age, int gender);
int Print_human(struct Human* human);