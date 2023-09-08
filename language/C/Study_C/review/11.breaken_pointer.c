#include <stdio.h>
void test(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void main() {
/*
	포인터를 깨부숴보자.

	1. 포인터의 크기는 8byte이다.
	2. 포인터 변수는 주소값을 가지고 있다.
	3. 포인터 변수의 타입은 주소값 다음 타입 크기만큼의 공간을 차지하게 된다.(배열에서 사용.) 
		ex. int *p [3] = {1,2,3}; 일 때, p[2] 는 *(p+2)와 같다.  
	4. *는 주소에 접근한다. &주소를 가져온다.로 생각하면 편하다.
*/
	int first = 1;
	int second = 2;
	int *p;
	p = &first;
	printf("%d %d\n", *p,first); // 즉, p가 x의 주소값에 접근하여 값을 불러왔기 때문에 x와 같은 값이 나온다.
	printf("%p %p\n", p, &first); // 역시 같은 주소값이다.
	
	printf("\n------1-----\n");

	test(&first, &second); // 함수에 주소값을 전해주어 연산이 가능하게 만들 수 있다.
	printf("first:%d second:%d", first, second);
	test(&first, &second); 

	printf("\n------2-----\n");

	const int* cp = &first; 
	cp = &second;
	printf("%d\n", *cp); // int에 const를 해준 결과 주소값을 바꿀 수 있었다.
	// 그러나 값인 int형에 접근하면 실행이 되지 않는다. *cp = first; (x)
	int* const pc = &first;
	//pc = &second; const를 주소값이 담긴 변수에 선언한다면 주소값을 바꿀 수 없다.
	*pc = 0;// 그러나 값은 변경이 가능하다.
	printf("%d\n", *pc);
	const int* const cpc = &first; // 예상 가능하듯, 주소값, 값 둘다 변경할 수 없다.

	printf("\n-----3------\n");

	int arr2[5][2] = { {1,2},{3,4},{5,6},{7,8},{9,10}};
	int arr3[2][2][2] = { {{1,2},{3,4}},{{5,6},{7,8}}};
	p = &arr2[0];
	for (int i = 0; i < sizeof(arr2) / 4; i++) {
		printf("%d %d\n", i, *(p + i));		
	}
	printf("%d\n", *(*(arr2 + 1)+1));		//  *(arr +1) = 2 즉 *(arr+1)+1);는 4 => 2에서 int 형의 크기인 +4만큼 주소값을 옮긴다.
	printf("%d\n", *(*(arr2 + 1)+2));		//  *(arr +1) = 2 즉 *(arr+2+1);는 4 => 2에서 +8만큼 주소값을 옮긴다.
	printf("%d\n", *(*(*(arr3 + 1)+1)+1));	//  arr주소값+4+8+8 즉 arr[0]에서 2칸 3칸 3칸 옮긴다. (8인 이유는 포인터의 주소값을 참조함으로 [8byte]이기 때문에 )

	printf("\n-----4------\n");
	int arr1[2] = { 0,1 };

	p = arr1; // p는 주소값을 가지고 있기 때문에 arr[0]의 주소값을 그냥 삽입할 수 있다.
	p = &arr1[0];//도 동일하다.

	for (int i = 0; i < 2; i++) {
		printf("%d\n", *(p + i));
	}

	while (p - arr1 <= 2) { // 포인터 타입으로 연산이 되기 때문에 가능.
		printf("%p %p\n", p, arr1);
		p++;
	}

	printf("\n-----5------\n");
	int** pp;
	pp = &p; // pp는 p의 주소값을 참조
	p = &first;
	printf_s("%d %d %d\n", **pp, * p, first); // pp는 참조에 참조

	printf("\n-----배열 포인터------\n");
	int(*arrp)[2];
	arrp = &arr1;
	printf("%d %d\n", (*arrp)[1], arr1[1]);

	int(*arrp2)[5][2];
	arrp2 = &arr2;
	printf("%d %d\n", (*arrp2)[1][1], arr2[1][1]);

	/* 다음에 한번더 보자. */
	int(*arrp3)[2];
	arrp3 = arr2;
	printf("%d %d\n", arrp3[1][1], arr2[1][1]);

	printf("\n-----7------\n");

	int* arr[2] = { &first,&second };
	for (int i = 0; i < 2; i++) {
		printf("%d\n", *arr[i]);
	}
	printf("pointer the end");
}