#include <iostream>
using namespace std;

int dp[31] = { 1,0,3, };

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	if (n % 2 == 1) {
		cout << 0;
		return 0;
	}
	
	
	for (int i = 4; i <= n; i+=2)
	{
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 0; j -= 2)
			dp[i] += dp[j] * 2;
	}

	cout << dp[n];
	return 0;
}