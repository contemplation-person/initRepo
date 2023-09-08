#pragma once
#include <stdio.h>

// 방식에는 r(읽기), w(쓰기) w+(쓰고 읽기)파일이 없으면 생성(덮어씌우기도 가능), r+(읽고 쓰기)파일이 없으면 읽지 않음.
// a는 덧붙이기 형식, a+ 읽기 덧붙이기 가능,

FILE* fp;
if (0 == fopen_s(&fp, "C:\\Users\\gkwnd\\Desktop\\a.txt", "w")) { // fopen_s(파일포인터의 주소값,"저장경로","방식") 
	fputs("hellowrld", stdout);//stdout 표준 출력 스트림.
	fputs("helloworld\n", fp); //fp에 기록,
	//fprintf(fp, "abc"); // 다른방법.
	fclose(fp);
}