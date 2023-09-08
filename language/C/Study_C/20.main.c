#include <stdio.h>

void main(int argc, char** argv) {
	printf("받은 인자의 개수: %d\n", argc);

	for(int i = 0;i<argc;i++){
		printf("이 프로그램의 경로: %s\n", argv[0]);
	}
}