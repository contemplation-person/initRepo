#include <string>
#include <vector>
#include <iostream>
#include <map>


using namespace std;

int solution(vector<vector<string>> clothes) {
	ios::sync_with_stdio(false); cin.tie(NULL);
    map<string, vector<string> > m;
    
    string type_name;
    int answer = 1;
    
    for (auto it = clothes.begin(); it != clothes.end(); it++)
    {
        m[(*it)[1]].push_back((*it)[0]);
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (answer)
        {
    	    answer *= it->second.size()+1;
        }
    }
    
        
    
    return answer - 1;
}