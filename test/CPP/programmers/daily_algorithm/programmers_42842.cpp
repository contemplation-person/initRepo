/* 다른 사람 풀이
    #include <string>
    #include <vector>

    using namespace std;

    vector<int> solution(int brown, int red) {

        int len = brown / 2 + 1;

        int w = len - 3;
        int h = 3;

        while(w >= h){
            if(w * h == (brown + red)) break;

            w--;
            h++;
        }
        return vector<int>{w, h};
    }
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int y_h = 1;
    int y_w = yellow;

    vector<int> answer;

    while (y_h <= y_w)
    {
        if (brown + yellow == (y_w + 2) * (y_h + 2) 
            && 4 + (y_h * 2) + (y_w * 2) == brown)
        {
            return (answer = {y_w + 2, y_h + 2});
        }
        y_h++;
        y_w = yellow / y_h;
    }
    return answer;
}