#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct S {
	int a;
}student;

void main() {
	int i = 1;

	student* s_cpy = (student*)malloc(i * sizeof(student));
	printf("%d\n", sizeof(s_cpy));
	free(s_cpy);
	
	i = 2;
	s_cpy = (student*)malloc(i * sizeof(student));
	printf("%d\n", sizeof(s_cpy));
	free(s_cpy);

	int* x = (int*)malloc(i * 4);
	printf("%d\n", sizeof(*x));
	
	i = 1;
	x = (int*)malloc(i*4);
	printf("%d\n", sizeof(*x));



}