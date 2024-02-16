/*
    문제
        지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M×N 크기의 보드를 찾았다.
        어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다.
        지민이는 이 보드를 잘라서 8×8 크기의 체스판으로 만들려고 한다.

        체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다.
        따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다.
        하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.

        보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8×8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다.
        당연히 8*8 크기는 아무데서나 골라도 된다.
        지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

    입력
        첫째 줄에 N과 M이 주어진다.
        N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다.
        둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다.
        B는 검은색이며, W는 흰색이다.

    출력
        첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.
*/


#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
/*
void print_chessBoard(vector<vector<int> > &r_v)
{
    for(int i = 0; i < r_v.size(); i++)
    {
        for (int s = 0; s < r_v[0].size(); s++)
            cout << r_v[i][s] << " " ;
        cout << endl;
    }
}
*/

void create_chessboard(int N, int M, vector<vector<int> >& r_v)
{
    char c;

    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j < M; j++)
        {
            cin >> c;
            temp.push_back(c == 'W');
        }
        r_v.push_back(temp);
    }
}

int cnt_changing_color(vector<vector<int> > r_v, int r_pos, int c_pos)
{
    int color_b = 0;
    int cnt_b = 0;

    for (int r_idx = 0; r_idx < 8; r_idx++)
    {
        // one line forword
        for (int c_idx = 7; c_idx > -1; c_idx--)
        {
            if (r_v[r_pos + r_idx][c_pos + c_idx] != color_b)
                cnt_b++;
            color_b = !color_b;
        }
        color_b = !color_b;
    }
    if (64 - cnt_b < cnt_b)
        return 64 - cnt_b;
    return cnt_b;
}

int main()
{
    int N, M;
    cin >> N >> M;  // N: 세로, M: 가로
    vector<vector<int> > r_v;
    create_chessboard(N, M, r_v);

    int min = 2147483646;
    int cnt = 0;
    int r_pos = 0;
    int c_pos = 0;

    do
    {
        cnt = cnt_changing_color(r_v, r_pos, c_pos);
        if (cnt < min)
            min = cnt;
        if (++c_pos + 7 >= M)
        {
            r_pos++;
            c_pos = 0;
        }
    } while (r_pos + 7 < r_v.size());
    cout << min << endl;
}

/* 내가 푼 문제
#include <stdio.h>

char arr[50][51];

inline bool f(char a)
{
    return a == 'W' ? 0 : 1;
}

int main()
{
    int x, y, cnt, mn = 32, n, m, i, j;

    scanf("%d%d", &n, &m);

    for (i = 0; i < n; i++)
        scanf("%s", arr[i]);

    for (i = 0; i < n - 7; i++)
    {
        for (j = 0; j < m - 7; j++)
        {
            cnt = 0;
            for (x = i; x < i + 8; x++)
                for (y = j; y < j + 8; y++)
                    cnt += f(arr[x][y]) == (x + y) % 2;
            cnt = cnt > 32 ? 64 - cnt : cnt;
            mn = cnt < mn ? cnt : mn;
        }
    }
    printf("%d", mn);
    return 0;
}
*/