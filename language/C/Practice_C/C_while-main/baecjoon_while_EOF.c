#include <stdio.h>

int main() {
/*
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)
EOF(end of file)이용 // 파일을 읽어 올 것이 없으면 -1을 도출하는 함수.
scanf 함수는 일반적으론 받은 수를 도출하지만, 에러나 EOF를 만나면 -1을 return한다.
*/

    int A,B;
    
    while (scanf_s("%d %d", &A,&B) != EOF) {
        if (A != 0 && B != 0) printf("%d\n", A + B);
    }
    //실험
/*    while (-1 != EOF) {
        if (A != 0 && B != 0) printf("%d\n", A + B);
    }
    결과 -1을 받았기 때문에 작동하지 않음.
*/
return 0;
}