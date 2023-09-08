#pragma once
#include <stdio.h>

char menu() {
	char select[2];
	scanf_s("%s", select, sizeof(select));
	return select[0];
}