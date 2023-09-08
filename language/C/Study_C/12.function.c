#include <stdio.h>
int hello() {
printf("hello Funtion\n");
return 0;
}

int magicbox() {
	//i += 4; // 오류 : 메인 함수내에서 정의된 지역변수를 magic box에서 사용하려 하였으므로....
	return 0;
}

int slave(int master_money) {
	master_money += 100000;
	return master_money;
}

/*
	문제 1
	어느날 귀족이 돈벌이가 시원치 않아져서 이전에는 일정하게 10000 달러씩 챙겼지만 이제 일정치 않은 수입을 얻게 되었습니다. 
	여러분은 slave 함수를 인자를 2 개를 가져서, 하나는 현재 귀족의 재산, 다른 하나는 오늘 귀족의 수입을 인자로 전달받는 새로운 함수를 만들어 보세요 
	(난이도 : 下)
*/
int slave_now(int cur, int today) {
	printf("현재의 재산은 : %d\n오늘 수입은 %d\n", cur, today);
	return cur + today;
}
/*
	문제3
	1 부터 n 까지의 합을 구하는 함수를 작성해보세요. 
	수학적인 공식을 써도 되지만 for 문으로 작성하는 것이 연습 하는데에는 도움이 될듯 합니다.
*/
int one_n(int n) {
	int temp=0;
	for (int i = 1; i < n+1; i++) {
		temp = temp + i;
	}
	return temp;
}

int prime(int n) {

	int cnt = 0,temp=0;

	for (int i = 1; i < n+1; i++) {
		if (i == 1)continue;

		for (int j = 1; j < i; j++) {
			if (i % j == 0)temp += 1;
			if (j != i-1) continue;
			if (temp ==1 ) {
				cnt++;
				printf("%d ", i);
			}
			temp = 0;
		}
	}
	printf("\n");
	return cnt;
}


void main() {  // main()함수의 경우 반환값을 운영체제가 받아드림
	//int i ;//magicbox 실험.
	printf("%d\n", hello());

	printf("-----------------------\n");

	printf("%d\n", slave(100)); // call by value
	
	printf("-----------------------\n");

	printf("수입의 총계 : %d\n", slave_now(1000, 234));

	printf("-----------------------\n");

	printf("1부터 N까지 더한 값은? %d\n", one_n(5));

	printf("-----------------------\n");

	printf("추출 숫자를 입력해주세요\n");
	int prime_num;
	scanf_s("%d", &prime_num);

	printf("%d\n", prime(prime_num));

}