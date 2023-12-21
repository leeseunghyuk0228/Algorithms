#include <iostream>
using namespace std;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)dp[i][0] = dp[i][i]= 1;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;

	cout << dp[n][k];

	return 0;
}
