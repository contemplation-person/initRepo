#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int cnt;
    int std;
    std::vector<int> arr;

    std::cin >> cnt;
    for (int tmp, i = 0; i < cnt; i++)
    {
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    std::cin >> std;
    std::cout << std::count(arr.begin(), arr.end(), std) << std::endl;
}