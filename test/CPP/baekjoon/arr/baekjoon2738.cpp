#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

int main()
{
    int **dp;
    int row;
    int col;

    scanf("%d %d", &row, &col);

    dp = (int **)malloc(sizeof(int *) * col);
    for (int i = 0; i < col; i++)
        dp[i] = (int *)malloc(4 * row);

    int num;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            scanf("%d", &(dp[i][j]));
        }
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            scanf("%d", &num);
            dp[i][j] += num;
        }
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%d", dp[i][j]);
            if (j != row - 1)
                printf(" ");
        }
        if (col - 1 != i)
            printf("\n");
    }
}