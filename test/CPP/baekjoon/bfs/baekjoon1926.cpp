#include <iostream>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
/*문제
어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라.
단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자
가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다
그림의 넓이란 그림에 포함된 1의 개수이다

입력
첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다
두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다
(단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)

출력
첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라
단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.*/
void print_v(vector<vector<int>> r_v)
{
    cout << "------ map ------" << endl;
    for (int i = 0; i < r_v.size(); i++)
    {
        for (int j = 0; j < r_v[i].size(); j++)
        {
            cout << r_v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------ done ------" << endl;
}

#define VISIT 0
#define EAST 1
#define NORTH -1
#define WEST -1
#define SOUTH 1

void init_input(vector<vector<int>> &r_v, vector<int> &c_v, int &row, int &column, int tmp)
{
    cin >> row >> column;

    r_v.reserve(row);
    c_v.reserve(column);

    for (int i = 0; i < row; i++)
    {
        c_v.clear();
        for (int j = 0; j < column; j++)
        {
            cin >> tmp;
            c_v.push_back(tmp);
        }
        r_v.push_back(c_v);
    }
}

void bfs(vector<vector<int>> &r_v, queue<pair<int, int>> &q, int &tmp)
{
    tmp++;
    if (q.front().first + SOUTH < r_v.size() && r_v[q.front().first + SOUTH][q.front().second])
    {
        r_v[q.front().first + SOUTH][q.front().second] = VISIT;
        q.push(make_pair(q.front().first + SOUTH, q.front().second));
    }
    if (q.front().second + EAST < r_v.front().size() && r_v[q.front().first][q.front().second + EAST])
    {
        r_v[q.front().first][q.front().second + EAST] = VISIT;
        q.push(make_pair(q.front().first, q.front().second + EAST));
    }
    if (q.front().first > 0 && r_v[q.front().first + NORTH][q.front().second])
    {
        r_v[q.front().first + NORTH][q.front().second] = VISIT;
        q.push(make_pair(q.front().first + NORTH, q.front().second));
    }
    if (q.front().second > 0 && r_v[q.front().first][q.front().second + WEST])
    {
        r_v[q.front().first][q.front().second + WEST] = VISIT;
        q.push(make_pair(q.front().first, q.front().second + WEST));
    }
    q.pop();
}

int main()
{
    ios::sync_with_stdio(false);

    int row;
    int column;
    int tmp;
    int paint_cnt = 0;
    int big_paint_area = 0;
    int cnt_one = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> r_v;
    vector<int> c_v;

    init_input(r_v, c_v, row, column, tmp);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (r_v[i][j])
            {
                // print_v(r_v);
                r_v[i][j] = VISIT;
                q.push(make_pair(i, j));
                paint_cnt++;
                tmp = 0;
                while (!q.empty())
                {
                    bfs(r_v, q, tmp);
                }
                if (big_paint_area < tmp)
                {
                    big_paint_area = tmp;
                }
            }
        }
    }

    cout << paint_cnt << endl
         << big_paint_area << endl;
}
