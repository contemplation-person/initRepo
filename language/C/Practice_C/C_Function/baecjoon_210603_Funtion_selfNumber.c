#include <stdio.h>
#include <stdlib.h>
/*
셀프 넘버는 1949년 인도 수학자 D.R. Kaprekar가 이름 붙였다. 
양의 정수 n에 대해서 d(n)을 n과 n의 각 자리수를 더하는 함수라고 정의하자. 

예를 들어, d(75) = 75+7+5 = 87이다.

양의 정수 n이 주어졌을 때, 이 수를 시작해서 n, d(n), d(d(n)), d(d(d(n))), ...과 같은 무한 수열을 만들 수 있다.

예를 들어, 33으로 시작한다면 다음 수는 33 + 3 + 3 = 39이고, 그 다음 수는 39 + 3 + 9 = 51, 다음 수는 51 + 5 + 1 = 57이다. 
이런식으로 다음과 같은 수열을 만들 수 있다.

33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...

n을 d(n)의 생성자라고 한다. 
위의 수열에서 33은 39의 생성자이고, 39는 51의 생성자, 51은 57의 생성자이다. 
생성자가 한 개보다 많은 경우도 있다. 예를 들어, 101은 생성자가 2개(91과 100) 있다.

생성자가 없는 숫자를 셀프 넘버라고 한다. 
100보다 작은 셀프 넘버는 총 13개가 있다. 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, 97

10000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

1 3 5 7 9 20 31   <-- a lot more numbers--> 9982 9993
	
	0. int 배열 10000 생성 및 그 안에 1~10000숫자 삽입,
	1. 자리 (숫자) == 자리수 출력
	2. 값 (숫자, 자리) == 숫자와 각자리의 숫자를 더함
	3. 생성된 수가 있으면 배열에 해당 배열에 0값 삽입.
	4. 반복문으로 0이 아닌 수 출력.
*/
int symbolRank(int num);
int value(int num, int sR);

int main() {
	int arr[10000] = { 0, };
	
	for (int i = 0; i < 10000; i++) {
		arr[i] = (i+1);
	}
	for (int i = 1; i <= 10000; i++) {
		if(value(i, symbolRank(i)) < 10000) arr[value(i, symbolRank(i)) - 1 ] = 0;
	}
	for (int i = 0; i < 9999; i++) {
		if(arr[i]!=0) printf("%d\n", arr[i]);
	}

/*
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		if (arr[i] != 0)printf("%d\n", arr[i]);
	}
*/
	
return 0;
}

int symbolRank(int num) {
	int sR=0;
	if (num < 10)	sR = 1;
	else if (num < 100)	sR = 2;
	else if (num < 1000) sR = 3;
	else if (num < 10000) sR = 4;

	return sR;
}

int value(int num, int sR) {
	switch (sR) { // switch 문에서 break 빼먹지 말자.....
		case 1: {
			num += num;
			break;
		}
		case 2: {
			num = num+(num/10)+(num%10);
			break;
		}
		case 3: {
			num = num+num/100+(num%10%10)+(num/10%10);
			break;
		}
		case 4: {
			num = num+num/1000+(num%10%10%10)+(num/10%10%10)+(num/100%10%10);
			break;
		}
	}
	return num;
}