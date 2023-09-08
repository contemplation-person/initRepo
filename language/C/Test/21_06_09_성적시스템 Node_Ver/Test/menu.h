#pragma once
#include <stdio.h>

char menu() {
	char select[1];
	scanf_s("%s", select, sizeof(select));
	return select[0];
}