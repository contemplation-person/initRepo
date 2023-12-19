#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> arr = {2, -3, 10};
    // 정방향 순열
    std::sort(arr.begin(), arr.end()); // 꼭 정렬을  해야함
    do
    {
        for (int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << ' ';
        std::cout << std::endl;
    } while (std::next_permutation(arr.begin(), arr.end()));

    // 역방향 순열
    std::sort(arr.begin(), arr.end(), std::greater<int>());
    do
    {
        for (int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << ' ';
        std::cout << std::endl;
    } while (std::prev_permutation(arr.begin(), arr.end()));


    std::cout << "done" << std::endl;
}