#include <stdio.h>

int main() {
    /*
    사분면 고르기 (x,y) 
    */
    int a = 0,b=0;
    scanf_s("%d", &a);
    scanf_s("%d", &b);
    a * b >= 0 ? a < 0 ? printf("1") : printf("4") : a < 0 ? printf("2") : printf("3");
    return 0;
}