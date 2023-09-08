#include <stdio.h>

int main() {
    /*
    n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.
    

    */
    int num;
    scanf_s("%d", &num);
    int temp = 0;
    for (int i = 0; i < num; i++) {
        temp += i + 1;
    }
    printf_s("%d", temp);
    return 0;
}