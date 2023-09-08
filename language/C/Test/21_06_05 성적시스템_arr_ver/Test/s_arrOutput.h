#pragma once
#include "grade.h"
#include "struct.h"
#include <stdio.h>
void s_outputAll(student* s_arr, int cnt) {
	for (int i = 0; i < cnt; i++) {
		printf("이름 : %s 나이 : %d 학번 : %d 성적 : %d\n", (s_arr + i)->name, ((s_arr + i)->age), ((s_arr + i)->s_num), ((s_arr + i)->score));
	}
}
void s_output(student* s_arr, int cnt) {
	for (int i = cnt-1; i < cnt; i++) {
		printf("이름 : %s 나이 : %d 학번 : %d 성적 : %d\n", (s_arr + i)->name, ((s_arr + i)->age), ((s_arr + i)->s_num), ((s_arr + i)->score));
	}
}
void s_outputAll_grade(student* s_arr, int cnt) {
	for (int i = 0; i < cnt; i++) {
		if(grade((s_arr + i)->score)==1){ 
			printf("이름 : %s 나이 : %d 학번 : %d 성적 : %d 등급 : 성적오류\n", (s_arr + i)->name, ((s_arr + i)->age), ((s_arr + i)->s_num), ((s_arr + i)->score));
		} else {
			printf("이름 : %s 나이 : %d 학번 : %d 성적 : %d 등급 : %c\n", (s_arr + i)->name, ((s_arr + i)->age), ((s_arr + i)->s_num), ((s_arr + i)->score), grade((s_arr + i)->score));
		}
	}
}