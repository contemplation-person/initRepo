/* The solution provided by others

    #include <string>
    #include <vector>
    #include <iostream>

    using namespace std;

    int solution(vector<vector<int>> sizes)
    {
        int w = 0;
        int h = 0;

        for (auto v : sizes)
        {
            w = max(w, min(v[0], v[1]));
            h = max(h, max(v[0], v[1]));
        }
        return w * h;
    }
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<int> row;
    vector<int> col;

    for (vector<int> v: sizes)
    {
        if (v[0] > v[1])
            swap(v[0],v[1]);
        row.push_back(v[0]);
        col.push_back(v[1]);
    }
    sort(row.begin(), row.end(), greater<>{});
    sort(col.begin(), col.end(), greater<>{});
    return row[0] * col[0];
}