#pragma once
#include "s_arrOutput.h"
#include <string.h>
#include <stdlib.h>

student* s_delete(student* origin, int cnt, int cnt_all) {
	cnt_all--;
	student* s_temp = (student*)malloc(sizeof(student) * cnt_all);

	if (cnt_all == 0) {
		s_output(origin, cnt);
		printf("값이 삭제되었습니다.\n");
		return NULL;
	}

	for (int i = 0; i < cnt_all; i++) {
		if(i >= cnt-1){
			strcpy_s((s_temp + i)->name, 10, (origin + i+1)->name);
			(s_temp + i)->age= (origin + i+1)->age;
			(s_temp + i)->s_num= (origin + i+1)->s_num;
			(s_temp + i)->score= (origin + i+1)->score;
		} else {
			strcpy_s((s_temp + i)->name, 10, (origin + i)->name);
			(s_temp + i)->age= (origin + i)->age;
			(s_temp + i)->s_num= (origin + i)->s_num;
			(s_temp + i)->score= (origin + i)->score;
		}
		
	}

	s_output(origin, cnt);
	free(origin);

	return s_temp;
}