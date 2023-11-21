#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    vector<int> v = { 1, 12, 3, 24, 5, 16, 7, 58, 9 };
    priority_queue<int, std::vector<int>, std::greater<int> > minpq(v.begin(), v.end());

    std::cout << "in pq : 1, 12, 3, 24, 5, 16, 7, 58, 9" << std::endl;

    std::cout << "out pq : ";
    while (42)
    {
        std::cout << minpq.top() << ", ";
        minpq.pop();
        if (minpq.empty())
            break;
    }
    cout << endl;
}