#pragma once
#include "struct.h"
#include "s_arrOutput.h"
#include <string.h>

student* s_insert(student* origin, int cnt,int cnt_all) {
	student* s_temp = origin;
	//printf("origin: %d origin* %d\n", sizeof(origin),sizeof(*origin));
	origin = (student*)realloc(origin, sizeof(*origin)*cnt_all);

	for (int i = 0; i < cnt_all; i++) {
		if (i == cnt-1) {
			char name[10];
			int age, s_num, score;
			scanf_s("%s %d %d %d", name,sizeof(name), &age, &s_num, &score);
			strcpy_s((origin + i)->name, 10, name);
			(origin + i)->age = age;
			(origin + i)->s_num = s_num;
			(origin + i)->score = score;
			continue;
		}
		strcpy_s((origin + i)->name, 10, (s_temp + i)->name);
		(origin + i)->age = (s_temp + i)->age;
		(origin + i)->s_num = (s_temp + i)->s_num;
		(origin + i)->score = (s_temp + i)->score;
	}
	s_output(origin,cnt);
	return origin;	
}