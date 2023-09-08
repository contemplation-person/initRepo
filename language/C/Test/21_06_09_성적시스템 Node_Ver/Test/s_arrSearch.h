#pragma once
#include "struct.h"
#include <string.h>
#include <stdio.h>
/*
	같으면 그 번호의 index를 반환.
*/
int s_search(char* searchWord, student* data,int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (!strcmp(searchWord, (data + i)->name)) { //strcmp == 같으면 0반환.
//			printf("i값 반환 :%d\n", i);
			return i+1;
		}
	}
	return 0;
}