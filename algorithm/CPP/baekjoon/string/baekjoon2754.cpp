/*
    A+: 4.3, A0: 4.0, A-: 3.7
    B+: 3.3, B0: 3.0, B-: 2.7
    C+: 2.3, C0: 2.0, C-: 1.7
    D+: 1.3, D0: 1.0, D-: 0.7
    F: 0.0
*/
#include <cstdio>
int main()
{

    char str[3];
    while (true)
    {
        float score = 0;
        scanf("%s", str);
        printf("%s :", str);
        switch (str[0])
        {
        case 'A':
            score = 4;
            break;
        case 'B':
            score = 3;
            break;
        case 'C':
            score = 2;
            break;
        case 'D':
            score = 1;
            break;
        default:
            score = 0;
            printf("%.0f\n", score);
            return 0;
        }
        switch (str[1])
        {
        case '+':
            score += 0.3;
            break;
        case '-':
            score -= 0.3;
        }
        printf("%.1f\n", score);
    }
}