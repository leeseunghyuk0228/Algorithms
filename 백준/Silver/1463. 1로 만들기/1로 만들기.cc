#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];

int main() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= 1000000; i++) {
		int MIN = 30;
		if (i % 3 == 0) MIN = min(dp[i / 3] + 1, MIN);
		if (i % 2 == 0) MIN = min(dp[i / 2] + 1, MIN);
		MIN = min(dp[i - 1] + 1, MIN);
		dp[i] = MIN;
	}

	int n; cin >> n;
	cout << dp[n];
	return 0;
}
