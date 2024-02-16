#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int max = citations.size();
    
    sort(citations.begin(), citations.end());
    
    int min = citations[0];
    
   	for (int i = max; i > min; i--)
    {
        if (i <= citations[citations.size() - i])
            return i;
    }
}