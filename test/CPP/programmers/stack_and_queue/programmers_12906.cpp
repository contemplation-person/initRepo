#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        if (it != arr.begin())
        {
            if (*it != *(it - 1))
                answer.push_back(*it);
        }
        else
            answer.push_back(*it);
    }
    return answer;
}