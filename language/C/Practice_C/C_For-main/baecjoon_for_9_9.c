#include <stdio.h>

int main() {
    /*
    출력형식과 같게 N*1부터 N*9까지 출력한다.
    2 * 1 = 2
    ...
    2 * 9 = 18

    */
    int num;
    scanf_s("%d", &num);

    for (int i = 1; i < 10; i++) {
        printf_s("%d * %d = %d\n", num, i, num * i);
    }
    return 0;
}