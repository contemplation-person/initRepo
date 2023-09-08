#include <stdio.h>

void main() {
	FILE* fp;
	char buf[20];// 내용 입력받을 곳.
	if (0 == (fopen_s(&fp, "C:\\Users\\gkwnd\\Desktop\\a.txt", "r"))) { 
		fgets(buf, 20, fp);
		printf("입력내용 %s\n", buf);
		fclose(fp);
	}
	
	printf("\n---------------------------------\n");
	char c;
	if(0==(fopen_s(&fp,"C:/Users/gkwnd/Desktop/a.txt","r"))){
		while ((c= fgetc(fp))!=EOF){ // EOF문자열 끝에 -1을 반환.
			printf("%c", c);
		}
		fclose(fp);
	}
	
	printf("\n---------------------------------\n");
	if (0 == fopen_s(&fp, "C:/Users/gkwnd/Desktop/a.txt", "r")) {
		fgetc(fp);
		fgetc(fp);
		fgetc(fp);
		fgetc(fp);

		fseek(fp, 0, SEEK_SET); // 위치 지정자를 변경시키는 함수, SEEK_SET (처음),SEEK_CUR (현재파일 포인터 위치), SEEK_END(파일의 끝)
		
		printf("%c\n", fgetc(fp));
		fclose(fp);
	}

	printf("\n---------------------------------\n");
	if (0 == fopen_s(&fp, "C:/Users/gkwnd/Desktop/a.txt", "w")) {
		fputs("this reperence", fp); // 위치지정자가 처음으로 변경된 다음. 덮어씀.
		fseek(fp, 0, SEEK_SET);// 다시 위치지정자 변경
		fputs("red...", fp);//덮어씀.

		fclose(fp);
	}
}