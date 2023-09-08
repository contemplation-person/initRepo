#include <stdio.h>
void main() {
	FILE* fp;
	char data[10];
	char c;

	if (0 == fopen_s( &fp, "C:/Users/gkwnd/Desktop/a.txt", "r")) {
		
		fgets(data, 5, fp); // \n까지나 두번째 인자 크기 -1까지 입력 받을 때
		printf("입력 받은 데이터 : %s \n", data);


		c = fgetc(fp);
		printf("그 다음에 입력 받은 문자 : %c \n", c);

		fseek(fp, -1, SEEK_CUR); // -면 왼쪽으로 이동.

		c = fgetc(fp);
		printf("그렇다면 무슨 문자가? : %c \n", c);

		fclose(fp);
	}
	if (fp == NULL) {
		printf("파일이 없어요!");
	}


}