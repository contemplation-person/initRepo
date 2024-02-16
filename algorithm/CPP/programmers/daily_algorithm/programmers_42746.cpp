#include <string>
#include <vector>
#include <algorithm>

using namespace std;
inline bool cmp(string& a, string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;
    for (int num : numbers)
        v.push_back(to_string(num));
    sort(v.begin(), v.end(), cmp);
    
    if (v[0] == "0") 
        return "0";
    for (string num : v)
        answer += num;
    return answer;
}