#include <stdio.h>

int main() {
/*
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)
입력의 마지막에는 0 두 개가 들어온다.
*/

    int A,B;
    do {
        scanf_s("%d", &A);
        scanf_s("%d", &B);
        printf("%d\n", A + B);
    } while (A != 0 && B != 0);

return 0;
}