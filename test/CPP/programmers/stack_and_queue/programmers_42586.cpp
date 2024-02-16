/*
    #include <string>
    #include <vector>
    #include <iostream>
    using namespace std;

    vector<int> solution(vector<int> progresses, vector<int> speeds) {
        vector<int> answer;

        int day;
        int max_day = 0;
        for (int i = 0; i < progresses.size(); ++i)
        {
            day = (99 - progresses[i]) / speeds[i] + 1;

            if (answer.empty() || max_day < day)
                answer.push_back(1);                                    // is good!
            else
                ++answer.back();                                        // is good!          

            if (max_day < day)
                max_day = day;
        }
        return answer;
    }
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    std::ios::sync_with_stdio(false);

    int day = 0;
    int cnt = 0;

    vector<int> a;

    for (auto s_it = speeds.begin(), p_it = progresses.begin(); s_it != speeds.end();) 
    {
        if ((*p_it) + (*s_it) * day >= 100)
        {
            cnt++;
            s_it++;
            p_it++;
        } 
        else if ((*p_it) + (*s_it) * day < 100)
        {
            day++;
            if (cnt != 0)
            {
                a.push_back(cnt);
            }
            cnt = 0;
        }
    }
    a.push_back(cnt);

    return a;
}