#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

bool is_prime_num(int num)
{
    if (num < 2) 
        return false;
    if (num == 2) 
        return true;
    for (int i = 2; i <= sqrt(num); i++)
    {
      	if (!(num % i)) 
            return false; 
    }
    return true;
}

int solution(string numbers) {
    int num = 0;
    set<int> s;

    sort(numbers.begin(), numbers.end());
    
    do 
    {
       	for (int i = 1; i <= numbers.size(); i++)
        {
            stringstream ss(numbers.substr(0, i));
            ss >> num;
            if (is_prime_num(num))
                s.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    return s.size();
}