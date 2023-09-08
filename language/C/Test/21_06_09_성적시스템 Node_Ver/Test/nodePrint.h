#pragma once
#include "struct.h"
#include "grade.h"
void nodePrint (student *st) {
	printf("이름 : %s, 나이 : %d, 학번 : %d, 점수 : %d , 성적 : %c\n", st->name, st->age, st->s_num, st->score, grade(st->score));
}

void nodeAllPrint(student * first) {
	if (first->name == NULL) printf("데이터가 없습니다.\n");
	student* next = first;
	while (next != NULL) {
		nodePrint(next);
		next = next->nextNode;
	}
}