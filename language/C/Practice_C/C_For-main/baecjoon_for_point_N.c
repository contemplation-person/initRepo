#include <stdio.h>

int main() {
    /*
    자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
    */

    int a;
    scanf_s("%d", &a);

    for (int i = 0; i < a; i++) {
        printf("%d", i+1);
     }
     return 0;

}