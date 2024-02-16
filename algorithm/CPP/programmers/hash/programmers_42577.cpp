#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    int cnt;
    for (auto it = phone_book.begin(); it < phone_book.end(); it++)
    {
        cnt = 0;
        for (auto it_2 = it; it_2 < phone_book.end(); it_2++)
        {
            if (!it->compare(0, it->size(), *it_2, 0, it->size()))
            {
                if (cnt)
                {
                    return false;
                }
                cnt++;
            }
            else if (it->size() > it_2->size())
                continue;
            else
                break;
        }
    }
    return true;
}