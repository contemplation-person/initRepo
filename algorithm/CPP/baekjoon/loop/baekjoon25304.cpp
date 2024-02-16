#include <iostream>

int main()
{
    long sum(0);
    long cmp;
    long cnt;

    std::cin >> cmp;
    std::cin >> cnt;
    for (long num, pay, i = 0; i < cnt; i++)
    {
        std::cin >> pay;
        std::cin >> num;
        sum += pay * num;
    }
    sum == cmp ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;
}