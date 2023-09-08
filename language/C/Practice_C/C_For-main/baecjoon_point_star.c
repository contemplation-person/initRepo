#include <stdio.h>

int main() {
    /*
    자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
    */

    int a;
    scanf_s("%d", &a);

    for (int i = 1; i <= a; i++) {
        for(int j = 0;j<i;j++) printf("*");
        printf("\n");
     }
     return 0;

}