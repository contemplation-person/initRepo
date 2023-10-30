#include <vector>
using namespace std;

typedef vector<int>::iterator v_it;

int solution(vector<int> nums)
{
    int answer = 0;
    int my_max_choice = nums.size() / 2;
    int type_nums[200001] = {0,};
    
    for (v_it it = nums.begin(); it < nums.end(); it++)
    {
        if (!type_nums[*it])
        {
            type_nums[0]++;
            type_nums[*it] = 1;
        }
    }
    return (type_nums[0] < my_max_choice ? type_nums[0] : my_max_choice);
}