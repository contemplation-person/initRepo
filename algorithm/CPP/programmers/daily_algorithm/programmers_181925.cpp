#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    for (auto it = numLog.begin() + 1; it != numLog.end(); it++)
    {
        switch (*it - *(it - 1))
        {
        case -1:
            answer.push_back('s');
            break;
        case 1:
            answer.push_back('w');
            break;
        case -10:
            answer.push_back('a');
            break;
        case 10:
            answer.push_back('d');
            break;
        }
    }
    return answer;
}