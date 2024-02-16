#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    switch ((int)a < b)
    {
    case 0:
        cout << a - b << endl;
        break;

    default:
        cout << -a + b << endl;
        break;
    }
}