#include <string>
#include <vector>

using namespace std;

/* 다른  사람의  풀이
    #include <algorithm>

    using namespace std;

    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> thr = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    vector<int> solution(vector<int> answers)
    {
        vector<int> answer;
        vector<int> they(3);
        for (int i = 0; i < answers.size(); i++)
        {
            if (answers[i] == one[i % one.size()])
                they[0]++;
            if (answers[i] == two[i % two.size()])
                they[1]++;
            if (answers[i] == thr[i % thr.size()])
                they[2]++;
        }
        int they_max = *max_element(they.begin(), they.end()); // 여기가 나랑의 차이점. 이 사람은 라이브러리를 떠올림. (비교를 한번 줄일 수 있음.)
        for (int i = 0; i < 3; i++)
        {
            if (they[i] == they_max)
                answer.push_back(i + 1);
        }
        return answer;
    }
*/
vector<int> solution(vector<int> answers) {
    vector<int> first = {1,2,3,4,5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int f_correct = 0;
    int t_correct = 0;
    int th_correct = 0;
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (first[i % 5] == answers[i])
        	f_correct++;   
        if (two[i % 8] == answers[i])
            t_correct++;
        if (three[i % 10] == answers[i])
            th_correct++;
    }
    vector<int> answer;
    
    if (f_correct >= t_correct && f_correct >= th_correct) 
        answer.push_back(1);
    if (t_correct >= f_correct && t_correct >= th_correct) 
        answer.push_back(2);
    if (th_correct >= f_correct && th_correct >= t_correct) 
        answer.push_back(3);
    return answer;
}