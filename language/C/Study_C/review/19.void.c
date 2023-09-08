#include <stdio.h>

//void 포인터 다시 공부 필요.
int read_char(void* p, int byte);

void main() {
	int arr[1] = { 0x12345678 };
	printf("%x\n", arr[0]);
	read_char(arr, 4);
}

int read_char(void* p, int byte) {
	do {
		printf("%x\n", *(char*)p);
		byte--;

		p = (char*)p + 1;
	} while (p && byte);

	return 0;
}