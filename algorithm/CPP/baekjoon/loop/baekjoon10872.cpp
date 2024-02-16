#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    if (num == 0)
    {
        std::cout << 1 << std::endl;
        return 0;
    }
    unsigned int ret = 1;
    for (int i = 1; i <= num; i++)
    {
        ret *= i;
    }
    std::cout << ret << std::endl;
}