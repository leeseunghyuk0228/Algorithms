#include <iostream>
#define MAX(a,b)((a>b)?a:b)
using namespace std;
int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s1, s2;
	
	cin >> s1 >> s2;
	int r = s1.length();
	int c = s2.length();

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (s1[i-1] == s2[j-1])dp[i][j] = dp[i-1][j - 1] + 1;
			else dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[r][c] << '\n';
}