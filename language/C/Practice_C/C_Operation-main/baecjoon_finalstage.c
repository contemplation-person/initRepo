#include <stdio.h>
int main() {
    int a = 0, b = 0;
    scanf_s("%d", &a);
    scanf_s("%d", &b);

    printf_s("%d\n", (b / 100)*a);
    printf_s("%d\n", (b / 10%10)*a);
    printf_s("%d\n", b%100%10*a);
    printf_s("%d\n", a * b);

}