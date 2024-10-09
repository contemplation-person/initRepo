/*
어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다. 
어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다. 
예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다. 
따라서 245는 256의 생성자가 된다. 
물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다. 
반대로, 생성자가 여러 개인 자연수도 있을 수 있다.
자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.
x = y = z <= 9
max_num(3자리) = a(3자리) + x + y + z
max_num - x - y - z = a
max_num - (x + y + z) = a
max_num - (max_minus = 9 * 3 = 27) = a
max_num - 27 < a < max_num 
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <string>


using namespace std;

int main() {
    int max_num;

    cin >> max_num;
    std::string str_num = to_string(max_num);

    for (int 생성자 = max_num - str_num.length() * 9; 생성자 < max_num; 생성자++) {
        std::vector<int> 자리수;

        for (int 분해값 = 생성자; 0 < 분해값;) {
            자리수.push_back(분해값 % 10);
            분해값 /= 10;
        }

        if (max_num == accumulate(자리수.begin(), 자리수.end(), 0) + 생성자) {
            std::cout << 생성자 << endl;
            return 0;
        }
    }

    std::cout << 0 << endl;
    return 0;
}
