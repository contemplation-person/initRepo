#include <stdio.h>

int main()
{
	const int a = 3;
	int *b = (int *)&a;
	*b = 5;
	printf("a : value = %d, address = %p\n", a, &a);
	printf("b : value = %d, address = %p\n", *b, b);
	return 0;
}