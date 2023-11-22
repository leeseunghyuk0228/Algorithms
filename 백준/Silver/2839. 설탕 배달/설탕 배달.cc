#include <iostream>
#include <algorithm>
using namespace std;

int dp[5001],n;

int main() {
	for (int i = 3; i < 5001; i++)dp[i] = -1;
	dp[3] = 1;
	dp[5] = 1;

	for (int i = 3; i < 5001; i++) {
		// 만들 수 없는 무게
		if (dp[i] == -1)continue;
		// 현재 위치에서 3하나 더한거
		if (dp[i + 3] == -1) dp[i + 3] = dp[i] + 1;
		else dp[i + 3] = min(dp[i] + 1, dp[i + 3]);
		// 현재 위치에서 5하나 더한거
		if (dp[i + 5] == -1) dp[i + 5] = dp[i] + 1;
		else dp[i + 5] = min(dp[i] + 1, dp[i + 5]);
	}

	cin >> n;
	cout << dp[n];


}