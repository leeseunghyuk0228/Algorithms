#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		int ans = 0,flag=0;
		cin >> s;
		for (char c : s)
		{
			if (c == '(')ans--;
			else ans++;
			if (ans > 0) 
			{
				cout << "NO\n";
				flag = 1;
				break;
			}
		}
		if (flag)continue;
		if (ans == 0)cout << "YES\n";
		else cout << "NO\n";
	}
}