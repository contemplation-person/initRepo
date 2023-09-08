#include <stdio.h>	
void main() {
/*
	char first[10] = { NULL, };
	scanf_s("%s", first, sizeof(first));
	printf("%s", first);
*/
/*
	char second[2][20];
	for (int i = 0; i < sizeof(second)/sizeof(second[2]); i++) {
		scanf_s("%s", second[i], sizeof(second[19]));
		printf("%s", second[i]);
	}
*/
	char third[2][2][20];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%s", third[i][j], sizeof(third[i][j])/sizeof(third[i][j][20]) );
			printf("%s\n", third[i][j]);
		}
	}
}