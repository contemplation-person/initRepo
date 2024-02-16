#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> pr, int lo)
{
    int max = *max_element(pr.begin(), pr.end());
    int cnt = 0;

    while (!pr.empty())
    {
        if (pr[0] == max)
        {
            cnt++;
            if (lo == 0)
                return cnt;
            pr.erase(pr.begin());
            max = *max_element(pr.begin(), pr.end());
        }
        else
        {
            pr.push_back(pr[0]);
            pr.erase(pr.begin());
        }
        lo--;
        if (lo < 0)
            lo = pr.size() - 1;
    }
}