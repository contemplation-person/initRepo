#include <stdio.h>

void main() {
	char test[3][4][20] = { "num" ,"name","major","st_num" };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < test[0][i][j]; j++) {
			printf("%c", test[0][i][j]);
		}
		printf("\t");
	}


	for (int i = 0; i < 3; i++) {
		printf("\n");
		for (int j = 0; j < 4; j++) {
				scanf_s("%s", test[i][j], 20);
				printf("%s ", test[i][j]);
		}		
	}	
}