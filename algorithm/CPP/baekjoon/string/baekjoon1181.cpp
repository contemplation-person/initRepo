#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct cmp
{
	bool operator()(const string &a, const string &b)
	{
		return a.size() < b.size();
	}
};

bool com(const string &a, const string &b)
{
	return a.size() < b.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	std::set<string> s;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
	vector<string> v(s.begin(), s.end());
	std::stable_sort(v.begin(), v.end(), cmp());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
	return 0;
}

/*
중요!
set은 첫번째 요소로 정렬을 해주고 그다음 두번째 요소로 정렬을 해준다!
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<pair<int, string>> h;
	string s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		h.insert(make_pair(s.size(), s));
	}
	for (auto i = h.begin(); i != h.end(); ++i)
		cout << i->second << endl;
}
 */