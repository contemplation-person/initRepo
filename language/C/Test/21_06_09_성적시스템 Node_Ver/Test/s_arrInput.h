#pragma once
#include "struct.h"
#include "s_arrOutput.h"
#include <stdio.h>

void s_input(student* s_arr, int cnt) {
	for (int i = cnt - 1; i < cnt; i++) {
		scanf_s("%s %d %d %d", (s_arr + i)->name, sizeof((s_arr + i)->name), &((s_arr + i)->age), &((s_arr + i)->s_num), &((s_arr + i)->score));
	}

	s_outputAll(s_arr, cnt);
}