#include <iostream>
using namespace std;
long long dp[1000000];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2])%15746;
	cout << dp[n];
}