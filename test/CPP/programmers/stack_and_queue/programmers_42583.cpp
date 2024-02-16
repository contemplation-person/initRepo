#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<int> q;
    int sum_weight = 0;

    for (int i = 0; i < bridge_length - 1; i++)
        q.push(0);
    
    int a = 0;
    
    for (int i = 0; i < truck_weights.size();)
    {
        if (sum_weight + truck_weights[i] <= weight)
        {
            sum_weight += truck_weights[i];
            q.push(truck_weights[i]);
            i++;
        }
        else if (!truck_weights.empty())
        {
            q.push(0);
        }
        sum_weight -= q.front();
        q.pop();
        a++;
    }
    return a + q.size() + 1;
}
/*
    #include <iostream>
    #include<algorithm>
    #include <functional>         // greater 사용 위해 필요
    #include <vector>
    #include<queue>
    using namespace std;

    int solution(int bridge_length, int weight, vector<int> truck_weights) {
        int answer = 0;
        int count = 0;
        int Time = 0;
        int Truck_weight = 0;
        queue<pair<int, int>> truck_move;

        while (true)
        {
            if (weight >= Truck_weight + truck_weights.at(count))
            {
                truck_move.push(make_pair(truck_weights.at(count), bridge_length + 1 + Time));
                Truck_weight += truck_weights.at(count);
                count++;
            }
            if (count >= truck_weights.size())
            {
                answer = truck_move.back().second;
                break;
            }
            else
            {
                Time++;
                if (truck_move.front().second == Time+1)
                {
                    Truck_weight -= truck_move.front().first;
                    truck_move.pop();
                }
            }
        }
        return answer;
    }
*/