#include <stdio.h>

int main() {
    /*
    두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
    

    */
    int num, num1,num2;
    scanf_s("%d", &num);

    for (int i = 1; i < num; i++) {
        scanf_s("%d", &num1);
        scanf_s("%d", &num2);
        printf_s("%d\n", num1+num2);
    }
    return 0;
}