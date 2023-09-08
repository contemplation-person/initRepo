#include <stdio.h>
int str_length(char* str);
int copystr(char* arr, char* arr1);
int stradd(int* arr, int* arr1);

void main() {
/*
	char null = 0 ==(char)NULL == '\0' ;

	string은 char의 null 문자로 문장의 끝을 판별한다.
	string은 char배열이다. 따라서 string == char[문장의 길이+1]이 된다.
*/
	char str[] = { "helloWorld" };
	printf("%d\n", str_length(str));
	str[3] = 'a';
	printf("%s\n", str);

printf("\n---------------------\n");

	char str1[20] = {NULL,};
	copystr(str, str1);
	printf("%s\n", str1);

printf("\n---------------------\n");
	stradd(str, str1);
	printf("%s\n", str1);
/*
*/
}

int str_length(char* str) {
	int i = 0;
	while (str[i]) { // 마지막에 0이 오므로 false;
		i++;
	}
	return i;
}

int copystr(char* arr, char* arr1) {
	while (*arr) {
		*arr1 = *arr;
		arr++;
		arr1++;
	}
	*arr = '\0';
	return 1;
}

int stradd(int* arr, int* arr1) {
	while (*arr1) {
		arr1++;
	}
	while (*arr) {
		*arr1 = *arr;
		arr++;
		arr1++;
	}
	arr1 = '\0';
	return 1;
}