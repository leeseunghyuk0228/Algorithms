#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct cmp
{
	bool operator() (string left, string right)
	{
		if (left.length() < right.length()) return false;
		if (left.length() > right.length()) return true;
		if (left < right)return false;
		if (left > right) return true;
		return false;
	}
};

priority_queue < string,vector<string>, cmp> q;
set<string>st;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	int n; cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (st.find(s) == st.end())
		{
			q.push(s);
			st.insert(s);
		}
	}

	while (!q.empty())
	{
		cout << q.top() << '\n'; q.pop();
	}
	return 0;
	
}