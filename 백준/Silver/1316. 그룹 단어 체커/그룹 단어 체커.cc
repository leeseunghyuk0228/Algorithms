#include <iostream>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,ans=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int arr[26] = { 0, };
		int flag = 1;
		int cursize = s.length();
		for (int idx = 0; idx < cursize; idx++)
		{
			if (arr[s[idx] - 97])
			{
				if (s[idx - 1] == s[idx])
					continue;
				else
				{
					flag = 0; break;
				}
			}
			else arr[s[idx] - 97] = 1;

		}
		ans += flag;
	}

	cout << ans;
}
