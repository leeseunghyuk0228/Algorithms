#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000][3];
int MIN = 21e8;
int N;

int main() {
	int t1,t2,t3;
	int res = 21e8;
	cin >> N;

	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

	for (int i = 1; i < N; i++) {
		cin >> t1 >> t2 >> t3;
		dp[i][0] = t1 + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = t2 + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = t3 + min(dp[i - 1][0], dp[i - 1][1]);
	}
	

	for (int i = 0; i < 3; i++) {
		res = min(res, dp[N - 1][i]);
	}
	cout << res;
	return 0;
}