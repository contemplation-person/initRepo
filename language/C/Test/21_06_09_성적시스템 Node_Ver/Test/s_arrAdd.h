#pragma once
#include "struct.h"
#include <stdlib.h>
#include <string.h>
#include "s_arrInput.h"
//		동적할당은 한 번만 가능함. 따라서 같은 동적할당에 재 동적할당을 한다고 늘어나는 것은 아님.
//		malloc 동적할당, calloc 초기화 동적할당, realloc 재동적할당. 


student* s_arrDefault(student* origin, int cnt) {
	origin = (student*)calloc(cnt , sizeof(student)); // calloc (길이, 타입의 크기);
	return origin;
}

student* s_arrCreate(student* origin, int cnt) {
	origin = (student*)malloc(cnt * sizeof(student)); // malloc (크기)
	s_arrDefault(origin, cnt);
	s_input(origin, cnt);
	return origin;
}

student* s_arrAdd(student* origin, int cnt) {
	student* s_temp = origin;
	origin = (student*)realloc(origin, cnt * sizeof(student)); // realloc(배열, 크기);

	s_arrDefault(origin, cnt);

	for (int i = 0; i < cnt - 1; i++) {
		strcpy_s((origin + i)->name, 10, (s_temp + i)->name);
		(origin + i)->age= (s_temp + i)->age;
		(origin + i)->s_num= (s_temp + i)->s_num;
		(origin + i)->score= (s_temp + i)->score;
	}
	s_input(origin, cnt);
	// 동적할당을 재할당한 것임으로 temp 메모리 해제를 하면 origin이 해제가 되어 문제발생.
	return origin;
}

