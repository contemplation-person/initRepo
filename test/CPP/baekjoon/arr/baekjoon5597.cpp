/*
입력은 총 28줄로 각 제출자(학생)의 출석번호 n(1 ≤ n ≤ 30)가 한 줄에 하나씩 주어진다. 출석번호에 중복은 없다.
*/

#include <iostream>
#include <cstring>

int main()
{
    int arr[31];
    memset(arr, 0, sizeof(arr));

    int cin;
    for (int i = 0; i < 28; i++)
    {
        std::cin >> cin;
        arr[cin] = 1;
    }
    for (int i = 1; i < 31; i++)
    {
        if (!arr[i])
            std::cout << i << std::endl;
    }
}