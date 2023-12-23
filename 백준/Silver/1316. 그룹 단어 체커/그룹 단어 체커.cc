#include <iostream>
#include <set>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,ans=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		set<char> st;
		string s;
		cin >> s;

		int flag = 1;
		int cursize = s.length();
		for (int idx = 0; idx < cursize; idx++)
		{
			if (st.find(s[idx]) != st.end())
			{
				if (s[idx] != s[idx - 1])
				{
					flag = 0; break;
				}
				continue;
			}
			st.insert(s[idx]);
		}
		ans += flag;
	}

	cout << ans;
}
