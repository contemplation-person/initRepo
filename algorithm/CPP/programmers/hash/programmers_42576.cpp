#include <string>
#include <vector>

using namespace std;
typedef vector<string>::iterator v_it;

string solution(vector<string> participant, vector<string> completion) {
    for (v_it it = completion.begin(); it < completion.end(); it++)
    {
     	participant.erase(it);
    }
    return 
}