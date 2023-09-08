#include <stdio.h>

int main() {
    int a = 0, b = 0;
    scanf_s("%d %d", &a, &b);
    printf("%lf", (double)a / b);
    return 0;
}