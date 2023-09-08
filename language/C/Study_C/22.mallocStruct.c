#include <stdio.h>
#include <stdlib.h>

struct Test {
	int a;
	int b;
};
void main() {
	struct Test* arr;
	int size;

	printf("구조체 배열의 크기");
	scanf_s("%d", &size);

	arr = (struct Test *)malloc(sizeof(struct Test) * size);
	
	for (int i = 0; i < size; i++) {
		scanf_s("%d %d %d", &(*arr).a, &arr->b);//,&arr[i].b
		printf("%d", arr[i].a);
		printf("%d", arr[i].b);
	}
	free(arr);
}