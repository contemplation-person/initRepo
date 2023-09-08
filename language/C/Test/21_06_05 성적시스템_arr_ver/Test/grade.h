#pragma once
#include <stdio.h>
char grade(int score) {
	if (score > 89 &&score <= 100) return 'A';
	else if (score > 79) return 'B';
	else if (score > 69) return 'C';
	else if (score > 59) return 'D';
	else if (score > 49) return 'E';
	else if (score >= 0) return 'F';
	else 	return 1;
}