#include <iostream>

int main()
{
    int a;
    std::cin >> a;
    for (int i = 0; i < a / 4; i++)
    {
        std::cout << "long ";
    }
    std::cout << "int" << std::endl;
}